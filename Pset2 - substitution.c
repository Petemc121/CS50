#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(int argc, string argv[])
{
 string key = argv[1];

if (argc == 1)
{
    printf("Please input a key\n");
    return 1;
} else
if (strlen(key) != 26)
{
    printf("Please input a 26 character key");
    return 1;
} else
{
  string  plainText = get_string("plaintext: ");
  int n = strlen(plainText);
  char *cipher;
  cipher = (char *) malloc(n);
    for (int i = 0; i< strlen(plainText); i++)
    {
       char letter = plainText[i];
       int ASCII = (int) plainText[i];
       char translation;
       int position = 0;
       int keyASCII = 0;
       int toLowerCase = 0;

        if (ASCII > 96 && ASCII < 123) {
           position = ASCII - 97;
           keyASCII = (int) key[position];
           if (keyASCII > 96 && keyASCII < 123) {
               toLowerCase = keyASCII;
           } else {
           toLowerCase = keyASCII + 32;
           }
          translation =  toLowerCase + 0;
        } else
        if (ASCII > 64 && ASCII < 91) {
         position = ASCII - 65;
         keyASCII = (int) key[position];
         if (keyASCII > 64 && keyASCII < 91) {
           translation = key[position];
         } else {
             translation = key[position] - 32;
         }
        } else {
           translation = letter;
        }

        cipher[i] = translation;
    }

    // string str = "hello";
    // strcat(cipher, &str);

    printf("ciphertext: %s\n", cipher);
    return 0;
}

}
