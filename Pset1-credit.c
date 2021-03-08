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

    long evenSum = 0;
    long oddSum = 0;

    long evenI;
    long oddI;

    int i;

    for (i=0;i<numLength;i++) {


        if (i % 2 == 0) {

       evenI = (num / myPow(10, i))%10;

       evenSum += evenI;

        printf("even: %li\n", evenI);

        } else {

            oddI = (num / myPow(10, i))%10;

            int oddItwo = oddI*2;

            if (oddItwo > 9) {

                int oddItwox = (oddItwo / myPow(10, 0))%10;
                int oddItwoxx = (oddItwo / myPow(10, 1))%10;

                oddItwo = oddItwox + oddItwoxx;
 printf("oddITwo: %i\n", oddItwo);
            }

            oddSum += oddItwo;

             printf("odd: %li\n", oddI);

        }



    }

    return evenSum + oddSum;

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

    long check = checkSum(inputOld, inputLength);

 printf("%li\n", inputLength);
 printf("%li\n", check);


if (inputLength == 15) {


  long first = (inputOld / myPow(10, inputLength - 1))%10;
  long second = (inputOld / myPow(10, inputLength - 2))%10;

    if (first == 3) {
        printf("valid!\n");
    }




     printf("%li\n", first);
      printf("%li\n", second);


  printf("%li\n", inputOld);

}








}
