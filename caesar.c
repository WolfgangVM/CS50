#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2) // caso a chave seja diferente de 2 ou inexistente exibe a mmsg de erro
    {
        printf("Usage: ./cesar key\n"); // caso não seja adicionado uma key ele explica
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i])) // se não for um numero gera umna msg de erro
        {
            printf("Usage: ./cesar key\n");
            return 1;
        }
    }

    int k = atoi(argv[1]); // cria variavel k, com base no argv usando atoi que converte caracter em inteiro

    string texto = get_string("Plaintext: "); // solicita ao usuario a mensagem que sera criptografada
    printf("Ciphertext: ");

    for (int j = 0; j < strlen(texto); j++) // cria um loop para gerar as cifras
    {
        if (isupper(texto[j])) // se a letra for mmaiuscula faz
        {
            printf("%c", (texto[j] -65 + k) % 26 + 65); // gera as cifras e mostra ao usuario
        }

        else if (islower(texto[j])) // se a letra for minuscula faz
        {
            printf("%c", (texto[j] - 97 + k) % 26 + 97); // gera as cifras e mostra ao usuario
        }
        else
        {
            printf("%c", texto[j]);
        }
    }
    printf("\n");
}
