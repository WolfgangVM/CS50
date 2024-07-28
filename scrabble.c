#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Ponntos
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // obtem palavras de entrada de ambos os jogadores
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Pontos dos dois participantes
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Printa o vencedor
    if ( score1 > score2)
    {
        printf ("Player 1 wins!\n" );
    }
    else if (score2 > score1)
    {
         printf ("Player 2 wins!\n" );
    }
    else
    {
        printf("Tie!\n");
    }

}

int compute_score(string word)
{
    int score = 0;

    for (int i = 0; i < strlen(word); i++) // continua o loop enquanto ouver caracters na palavra
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i]-'A']; // Calcula pontuação das letras maiusculas
        }
        if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a']; // Calcula pontuação das letras minusculas
        }
    }

    return score;

}
