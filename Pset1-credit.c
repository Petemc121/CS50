#include <stdio.h>
#include <cs50.h>

long myPow(long x,long n)
{
    int i; /* Variable used in loop counter */
    long number = 1;

    for (i = 0; i < n; i++)
        number *= x;

    return(number);
}

long checkSum(long num, long numLength) {

    long evenSum;
    long oddSum;

    for (i=0;i<numLength;i++) {

        long evenDig;
        long oddDig;

        if (i % 2 == 0) {

       evenDig = (num / myPow(10, numlength - i))%10;

       evenSum += evenDig*2

        } else {

            oddDig = (num / myPow(10, numlength - i))%10;

            oddSum += oddDig

        }


    }

}


int main(void) {

   long input;

   do {
         input = get_long("Number: ");
   }
   while(input < -1);



  long inputLength = 0;

  long inputOld = input;


   while (input > 0) {
    inputLength++;
    input = input/10;
  }

 printf("%li\n", inputLength);



if (inputLength == 15) {


  long first = (inputOld / myPow(10, inputLength - 1))%10;
  long second = (inputOld / myPow(10, inputLength - 2))%10;

    if (first == 3) {
        printf("valid!\n");
    }

}

     printf("%li\n", first);
      printf("%li\n", second);

  printf("%li\n", inputOld);



}
