#include <stdio.h>
#include <cs50.h>


int myPowNeg(float x,float n)
{
    float i; /* Variable used in loop counter */
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

  float inputLength = 0;



   while (input > 0) {
    inputLength++;
    input = input/10;
  }

  printf("%f", inputLength);


  float remain = inputLength/myPowNeg(10,-15)%10;

  printf ("%f", remain);

}
