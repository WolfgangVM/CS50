#include <stdio.h>
#include <cs50.h>
#include <math.h>

float get_money(void);

int main(void)

{

float money;
int result = 0;
int c25 =0;         // adicionei apenas pra conferir se estava funcionando corretamente }
int c10 =0;         // adicionei apenas pra conferir se estava funcionando corretamente }   Mantive porque ficou melhor
int c01 =0;         // adicionei apenas pra conferir se estava funcionando corretamente }

    do

    {

// aceita numeros positivos, negativos e fracionado
        money=get_float("Change owed: ");

    }

// money nnão pode ser menor ou igual a 0.009
        while (money <= 0.009);

//converte valor fracionado em inteiro. função math.h
int centavos = round (money * 100);

//printf ("%f\n", money); usar pra saber como o codigo se comprta
//printf ("%i\n", centavos); usar pra saber como o codigo se comprta

    while (centavos >=25)
    {
        centavos = centavos - 25;
        result++;
        c25++;
    }

    while(centavos >= 10)
    {
        centavos = centavos - 10;
        result++;
        c10++;
    }

    while(centavos >= 1)
    {
        centavos = centavos -1;
        result++;
        c01++;
    }

    printf ("\n O numero de moedas usadas é de %i\n\n", result);
    printf ("\nForam %i de 25c", c25);
    printf ("\nForam %i de 10c", c10);
    printf ("\nForam %i de 01c\n\n", c01);
}
