#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    int inicial;
    int final;

    do
    {
        inicial = get_int("Start size: ");
    }
    while(inicial < 9 ); // retorna caso não satisfaça as condições

    do
    {
         final = get_int("End size: ");
    }
    while( final < inicial);

int years = 0;

    for (int n = inicial; n < final; years++ )
    {
        n = n + trunc((n / 3)) - trunc((n / 4)); //calculo
    }

    printf("\nYears: %i\n\n", years );

}
