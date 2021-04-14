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

    if (score1 > score2) {
        printf("Player 1 wins!");
    } else if (score2 > score1) {
        printf("Player 2 wins!");
    } else {
           printf("Tie!");
    }
}

int compute_score(string word)
{

   int totalPoint = 0;

   //loops through each letter in the string, and tests its value using ASCII

   for (int i = 0; i < strlen(word); i++)
   {

       //casts an int value onto the char to use ASCII

        char letter = word[i];
        int number = (int)word[i];
        int point = 0;

       if (number > 96 && number < 123 ) {

           int position = number - 97;
          point = POINTS[position];

       } else
       if (64 < number && number < 91) {

           int position = number - 65;
          point = POINTS[position];

       } else {
         point = 0;

       }

       // adds letter value to total word value

       totalPoint = totalPoint + point;


   }

    printf("%s total: %i\n" , word, totalPoint);

   return totalPoint;


}
