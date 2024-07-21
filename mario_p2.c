#include <stdio.h>
#include <cs50.h>

int main (void){
int altura;

    do
    {
        altura = get_int("Digite um numero entre 1 e 8: ");
    }
    while(altura > 8 || altura < 1);

    for(int coluna=0; coluna < altura+1; coluna++)
    {
        for(int linha=0; linha < altura; linha++){
            printf(" ");
            if(linha+coluna > altura - 1)
            {
                printf("# ");
            }
            if(linha+coluna > altura - 1)
            {
                printf("#");
            }
        }
        printf("\n");
    }
    return 0;
}