#include <stdio.h>
#include <cs50.h>


int myPowNeg(int x,int n)
{
    int i; /* Variable used in loop counter */
    float number = 1;

    for (i = 0; i > n; --i)
        number /= x;

    return(number);
}


int main(void) {

   long input;

   do {
         input = get_long("Number: ");
   }
   while(input < -1);

  int inputLength = 0;



   while (input > 0) {
    inputLength++;
    input = input/10;
  }

  printf("%i", inputLength);

  if (inputLength == 15) {
    if ((inputLength/myPowNeg(10,-15)) % 10 == 3) {
      printf("that's 3");
    }
  }

}
