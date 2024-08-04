#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates || maximo de votos e candidatos
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i || matriz que relaciona os candidatos e votos
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status || estrutura que relaciona nome, votos e eliminação
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates || matriz de candidatos
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates || nummero de votos e candidatos
int voter_count;
int candidate_count;

// Function prototypes || prototipos de funções
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

// INICIO DO PROGRAMA PRINCIPAL
int main(int argc, string argv[])
{
    // Check for invalid usage || verifica se a entrada é valida
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates || verifica se a quantidade de candidatos está dentro do limite
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}
// FIM DO PROGRAMA PRINCIPAL

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{

       for(int i = 0; i < candidate_count; i++) //loop que continua deacordo com o numero de candidatos
    {
        if (strcmp(candidates[i].name, name) == 0)  // confere se o candidato existe
        {
            preferences[voter][rank] = i; // atribui o valor de "i" para a tabela de voto de acordo comm a preferencia do eleitor
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)   // loop que repete de acordo co o limite de votos
    {
        for (int j =0; j < candidate_count; j++)    // loop que repete de acordo com a quantidade de candidatos
        {
            if (candidates[preferences[i][j]].eliminated == false)  // verifica se o candidato foi elimmindado
            {
                candidates[preferences[i][j]].votes++;  // caso o candidato não tenha cido eliminado recebe o voto
                break;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    for ( int i = 0; i < candidate_count; i++)  //loop que repete até que i seja igual ao numero de candidatos
    {
        if (candidates[i].votes > voter_count/2)    //confere para saber se o candidato em questão tem mmais da metade dos votos
        {
            printf("%s\n", candidates[i].name); // printa na tela condidato que tem mais da mmetade dos votos
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min = voter_count;  // define o valor de "min" sendo iqual a dde "vouter_count"
    for (int i = 0; i < candidate_count; i++)   //loop que repete o mesmo numero de vezes que a quantidade de candidatos
    {
        if (candidates[i].votes < min && candidates[i].eliminated == false) //se o candidato tiver menos votos que "min" e não tenha cido eliminado(declarado eliminado ou true) executa o codigo
        {
            min = candidates[i].votes;  //"min" recebe o valor do candidato (no caso com mmenos votos que min anteriormente)
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise || verifica se ouve empate
bool is_tie(int min)
{
    int eliminate =0; //cria e define uma variavel
    int counter = 0;    //cria e define uma variavel
    for (int i = 0; i < candidate_count; i++)   //loop que repete de acordo com a quantidae de candidatos
        {
            if (!candidates[i].eliminated)  // coonfere se o candidato foi eliminado
            {
                eliminate ++;   //atribui mais 1 caso tenha cido elimindo para a variavel eliminate
            }
            if (candidates[i].votes == min) //confere se o candidatos tem o numero minimo de votos comparando com a variavel min que recebe o menor numero de votos de um candidato valido
            {
                counter ++; //atribui mais 1 para a variavel counter caso o candidato tenha o valor minimo de votos
            }
        }
        if (eliminate == counter)   //confere se o numero de eliminações e de votos minimos é igual, ou seja, ouve empate
        {
            return true;
        }
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)   //loop que repete de acordo com a quantidade de candidatos
    {
        if (candidates[i].votes == min) //verifica se o candidato tem a menor quantidade de votos
        {
            candidates[i].eliminated = true;    //tribui o valor boleano true, ou seja, canddidato eliminado da eleição 
        }
    }
    return;
}
