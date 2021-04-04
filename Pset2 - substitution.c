#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>



int main(int argc, string argv[])
{
 string key = argv[1];

if (strlen(key) == 0)
{
    printf("Please input a key");
    return 1;
} else
if (strlen(key) != 26)
{
    printf("Please input a 26 character key");
    return 1;
} else
{
  string  plainText = get_string("plaintext: ");
  string cipher = "";

    for (int i = 0; i< strlen(plainText); i++)
    {
       char letter = plainText[i];
       int ASCII = (int) plainText[i];
       char translation;

        if (ASCII > 96 && ASCII < 123) {
            int position = ASCII - 97;
           int keyASCII = (int) key[position];
          int  toLowerCase = keyASCII + 32;
          translation = (char) toLowerCase;
        } else
        if (ASCII > 64 && ASCII < 91) {
           int position = ASCII - 65;
           translation = key[position];

        } else {
           translation = letter;
        }

        cipher = cipher + translation;
    }

    printf("ciphertext: %s", cipher);
}

}
