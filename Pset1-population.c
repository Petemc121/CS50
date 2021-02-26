#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int popStart;

    do
    {
    popStart = get_int("Starting population? (must be positive and above 9)");
    }

    while (popStart < 9);

   int yearlyPop = popStart;

    int popEnd;

    do

    {
    popEnd = get_int("End population?");
    }

    while(popEnd<popStart);

   int birthRate = yearlyPop/3;

   int deathRate = yearlyPop/4;

   int years = 0;



   while (yearlyPop < popEnd)

   {

       years++;

      yearlyPop = yearlyPop + birthRate - deathRate;

       birthRate = yearlyPop/3;

       deathRate = yearlyPop/4;

    printf("%i\n", yearlyPop);
    }

   printf("Years: %i\n", years);
}
