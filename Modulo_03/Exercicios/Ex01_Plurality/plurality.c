#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Número máximo de candidatos
#define MAX 9

// Cada candidato possui um nome e um número de votos.
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array de candidatos.
candidate candidates[MAX];

// Número de candidatos
int candidate_count;

// Prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Checa por uso inválido
    if (argc < 2)
    {
        printf("Uso: ./plurality [candidato ...]\n");
        return 1;
    }

    // Preenchendo o Array de candidatos
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("O número máximo de candidatos é %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Número de eleitores: ");

    // Coleta os votos dos eleitores.
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Procura por votos inválidos.
        while(!vote(name))
        {
            printf("Voto inválido.\n");
            name = get_string("Vote: ");
        }
    }

    printf("Vencedor(es):\n\n");

    // Exibe o(s) candidato(s) vencedor(es).
    print_winner();
}

// Atualiza o total de votos dos candidatos.
bool vote(string name)
{
    for(int i = 0; i < candidate_count; i++)
    {
        if(!(strcmp(candidates[i].name, name)))
        {
            candidates[i].votes++;
            return true;
        }
    }

    return false;
}

// Exibe o vencedor (ou vencedores) da eleição.
void print_winner(void)
{
    int bigNum = 0;

    for(int i = 0; i < candidate_count; i++)
    {
        if(candidates[i].votes > bigNum)
        {
            bigNum = candidates[i].votes;
        }
    }

    for(int i = 0; i < candidate_count; i++)
    {
        if(candidates[i].votes == bigNum)
        {
            printf("%s\n", candidates[i].name);
        }
    }

    return;
}

