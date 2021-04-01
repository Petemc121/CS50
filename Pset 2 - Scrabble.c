#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};


int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
}

int compute_score(string word)
{

   int totalPoint = 0;

   for (int i = 0; i < strlen(word); i++)
   {
        char letter = word[i];
        int number = (int)word[i];
         printf ("ascii %i\n", number);
        int point = 0;

       if (number > 96 && number < 123 ) {

           int position = number - 96;
          point = POINTS[position];
          printf ("letter lower %i\n", point);

       } else
       if (64 < number && number < 91) {

           int position = number - 64;
          point = POINTS[position];
          printf ("letter high %i\n", point);
       } else {
           printf("Please use only letters in the alphabet.");
       }

       totalPoint = totalPoint + point;



   }

   return 1;

}
