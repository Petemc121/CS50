#include <stdio.h>
#include <cs50.h>


int myPow(int x,int n)
{
    int i; /* Variable used in loop counter */
    int number = 1;

    for (i = 0; i < n; ++i)
        number *= x;

    return(number);
}


int main(void) {

   long input;

   do {
         input = get_long("Number: ");
   }
   while(input < -1);



  int inputLength = 0;

  long inputOld = input;


   while (input > 0) {
    inputLength++;
    input = input/10;
  }

    if (inputLength == 15) {

  int first = (inputOld/(myPow(10,(13))))%10;
  int second = (inputOld/(myPow(10,(12))))%10;

    if (first == 3) {
        printf("valid1");
    }

     printf("%i\n", first);
      printf("%i\n", second);


    }

  printf("%i\n", inputLength);

  printf("%li\n", inputOld);



}
