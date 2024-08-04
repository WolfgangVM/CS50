#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates _ Numero maximo de candidatos
#define MAX 9

// Candidates have name and vote count _ Candidaos tem nome e votos
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates _ lista de candidatos
candidate candidates[MAX];

// Number of candidates _ numero de candidatos
int candidate_count;

// Function prototypes _ prototipos de funçõoes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage _ Checa se é valido para uso
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates _ preencher matriz de candidatos
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters _ lope de todos os votos
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote _ checa se o voto é valido
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election _ printa na tela o vencedor da eleição
    print_winner();
}

// Update vote totals given a new vote _ atualiza os votos
bool vote(string name)
{
    // TODO
    for (int i = 0; i < candidate_count; i++ )
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes ++;
            return true;
        }
    }

    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    int winner = candidates[0].votes;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > winner)
        {
            winner = candidates[i].votes;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == winner)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}

