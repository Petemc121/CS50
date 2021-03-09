#include <stdio.h>
#include <cs50.h>


//power function

long myPow(long x,long n)
{
    int i; /* Variable used in loop counter */
    long number = 1;

    for (i = 0; i < n; i++)
        number *= x;

    return(number);
}

//checksum function

long checkSum(long num, long numLength)
{

    long evenSum = 0;
    long oddSum = 0;

    long evenI;
    long oddI;

    int i;

    for (i=0;i<numLength;i++) {


        if (i % 2 == 0) {

       evenI = (num / myPow(10, i))%10;

       evenSum += evenI;



        } else {

            oddI = (num / myPow(10, i))%10;


            int oddItwo = oddI*2;

            if (oddItwo > 9) {

                // if x 2 is double digit, add the two digits together

                int oddItwox = (oddItwo / myPow(10, 0))%10;
                int oddItwoxx = (oddItwo / myPow(10, 1))%10;

                oddItwo = oddItwox + oddItwoxx;
            }

            oddSum += oddItwo;

        }
    }

    return evenSum + oddSum;

}


int main(void) {

    //get number input.

   long input;

   do {
         input = get_long("Number: ");
   }
   while(input < -1);

  long inputLength = 0;
  long inputOld = input;

//while loop to find input digit length

   while (input > 0) {
    inputLength++;
    input = input/10;
  }

    long check = checkSum(inputOld, inputLength);

    //check if checksum is valid

 if (check % 10 == 0) {

     //finds the nth digit in a number

  long first = (inputOld / myPow(10, inputLength - 1))%10;
  long second = (inputOld / myPow(10, inputLength - 2))%10;

  // validation for various types of cards

     if (inputLength == 15) {


         if (first == 3 && (second == 4 || second == 7)) {
                printf("AMEX\n");
            } else {
                printf("INVALID\n");
            }

            } else if (inputLength == 16) {

                if (first == 5 && (second == 1 || second == 2 || second == 3 || second == 4 || second == 5)) {
                    printf("MASTERCARD\n");
                } else if (first == 4) {
                    printf("VISA\n");
                }
            } else if (inputLength == 13) {
                 if (first == 4) {
                    printf("VISA\n");
                } else {
                    printf("INVALID\n");
                }

            } else {
                 printf("INVALID\n");
            }

 } else  {
   printf("INVALID\n");
 }

}
