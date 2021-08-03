#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;

bool start_of_new_jpeg(BYTE buffer1, BYTE buffer2, BYTE buffer3, BYTE buffer4);


int main(int argc, char *argv[])
{


    if (argc < 2 || argc > 2)
    {
        printf("Wrong number of file arguments.");
        return 1;
    } else

    {
         FILE *file = fopen(argv[1], "r");

         if (!file)
         {
              printf("Incorrect file format");
              return 1;
         } else
         {
            BYTE buffer[512];
            int jpeg = 0;
            char filename[8];
            FILE *img = NULL;
            bool have_found_first_jpeg = false;

             while(fread(&buffer, 512, 1, file) == 1)
             {
                 if (start_of_new_jpeg(buffer[0], buffer[1], buffer[2], buffer[3]) != 0)
                 {

                     if (!have_found_first_jpeg)
                     {
                         have_found_first_jpeg = true;
                     } else
                     {
                         fclose(img);
                     }

                        sprintf(filename, "%03i.jpg", jpeg);
                        img = fopen(filename, "w");
                        if (img == NULL)
                        {
                            return 1;
                        }
                        fwrite(buffer, 512, 1, img);
                        jpeg++;
                    } else if (have_found_first_jpeg)
                 {
                     fwrite(buffer, 512, 1, img);
                 }


             }
             fclose(img);
             fclose(file);

         }
    }


}

bool start_of_new_jpeg(BYTE buffer1, BYTE buffer2, BYTE buffer3, BYTE buffer4)
    {


           return buffer1 == 0xff && buffer2 == 0xd8 && buffer3 == 0xff && (buffer4 & 0xf0) == 0xe0;

    }

