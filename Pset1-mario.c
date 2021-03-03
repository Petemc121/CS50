#include <stdio.h>
#include <cs50.h>

int main(void) {

    int height;

    //Ask for height integer, and keep then asking while value is below 1 or above 8

    do {
     height = get_int("Height?");
    }
     while(height > 8 || height < 1);


    //for loop for each line of the pyramid

    for(int i = 1; i< height + 1; i++) {

        // For loop to print initial spaces

      for (int x = height; x>i; x--) {
                printf(" ");
            }

            //For loop to print #s

        for(int j = 0; j<i; j++) {

            printf("#");

        }

        //Print spaces between each half of the pyramid

        printf("  ");

        //Print second half of the pyramid

         for(int j = 0; j<i; j++) {

            printf("#");

        }

        //Start a new line

            printf("\n");
    }

}
