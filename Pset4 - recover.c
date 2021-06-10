#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;

bool start_of_new_jpeg(BYTE buffer);
bool first_jpeg();


int main(int argc, char *argv[])
{


    if (argc < 2 || argc > 2)
    {
        printf("File argument is absent.");
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
             while(fread(&buffer, 1, 512, file))
             {
                 if (start_of_new_jpeg(&buffer))
                 {
                     if (first_jpeg())
                     {

                     }
                     else
                     {

                     }
                 }
                 else
                 {

                 }
             }
         }
    }


}

bool start_of_new_jpeg(BYTE buffer)
    {
        for (int i = 0; i < sizeof(buffer); i++)
        {

           return buffer[i] == 0xff && buffer[i+1] == 0xd8 && buffer[i+2] == 0xff && (buffer[i+3] & 0xf0) == 0xe0;
        }
    }
