#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    string texto = get_string("Texto: ");

    int letras = 0;
    int palavras = 1; // Começa com 1 porque a primeira palavra não é precedida por um espaço
    int sentencas = 0;

    for (int i = 0; texto[i] != '\0'; i++)
    {
        char c = texto[i];
        if (isalpha(c)) // Verifica se c é uma letra
        {
            letras++;
        }
        else if (c == ' ') // Verifica se c é um espaço
        {
            palavras++;
        }
        else if (c == '.' || c == '!' || c == '?') // Verifica se c é um delimitador de sentença
        {
            sentencas++;
        }
    }

    float L = ((float) letras / palavras) * 100; // Média de letras por 100 palavras
    float S = ((float) sentencas / palavras) * 100; // Média de sentenças por 100 palavras

    int indice = round(0.0588 * L - 0.296 * S - 15.8); // Calcula o índice de Coleman-Liau

    if (indice >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (indice < 1)
    {
        printf("Before Grade 1\n"); 
    }
    else
    {
        printf("Grade %i\n", indice);
    }
}
