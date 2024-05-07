#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Máximo de eleitores e candidatos.
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] é a (j)ésima preferência do (i)ésimo candidato
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidatos possuem nome, contagem de votos, status de eliminado.
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array de candidatos.
candidate candidates[MAX_CANDIDATES];

// Números de eleitores e candidatos.
int voter_count;
int candidate_count;

// Prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Checa por uso incorreto.
    if (argc < 2)
    {
        printf("Uso: ./runoff [candidato ...]\n");
        return 1;
    }

    // Preenche o array de candidatos.
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("O número máximo de candidatos é: %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Número de eleitores: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("O número máximo de eleitores é: %i\n", MAX_VOTERS);
        return 3;
    }

    // Fica consultando para obter os votos.
    for (int i = 0; i < voter_count; i++)
    {

        // Consulta para cada rank.
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Grava o voto, a menos que seja inválido.
            if (!vote(i, j, name))
            {
                printf("Voto inválido.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Executa os "runoffs" até chegar a um vencedor.
    while (true)
    {
        // Calcula os votos com base nos candidatos restantes.
        tabulate();

        // Checa se a eleição possui um vencedor.
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Elimina os candidatos que estão na última posição.
        int min = find_min();
        bool tie = is_tie(min);

        // Se houver empate, os que ainda não foram eliminados vencem.
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

        // Elimina os candidatos que possuem o menor número de votos.
        eliminate(min);

        // Reseta a contagem de votos de todos os candidatos para 0.
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Grava a preferência se o voto é válido.
bool vote(int voter, int rank, string name)
{
    for(int i = 0; i < candidate_count; i++)
    {
        if(strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;

            // Verifica se o candidato já foi escolhido anteriormente.
            for(int j = 0; j < rank; j++)
            {
                if(preferences[voter][j] == preferences[voter][rank])
                {
                    return false;
                }
            }

            return true;
        }
    }

    return false;
}

// Calcula os votos para os candidatos que ainda não foram eliminados.
void tabulate(void)
{
    int voto;

    for(int i = 0; i < voter_count; i++)
    {
        for(int j = 0; j < candidate_count; j++)
        {
            voto = preferences[i][j];

            if(!candidates[voto].eliminated) // Se o candidato não estiver eliminado.
            {
                candidates[voto].votes++;
                break;
            }
        }
    }

    return;
}

// Exibe o(s) vencedor(es), se houver algum.
bool print_winner(void)
{
    int vencedores = 0;

    for(int i = 0; i < candidate_count; i++)
    {
        if(candidates[i].votes > voter_count/2)
        {
            printf("%s ", candidates[i].name);
            vencedores++;
        }
    }

    if(vencedores > 0)
    {
        printf("\n");
        return true;
    }

    return false;
}

// Retorna o menor número de votos que um ou mais candidatos ainda não eliminados possuem.
int find_min(void)
{
    int min = voter_count;

    for(int i = 0; i < candidate_count; i++)
    {
        if(candidates[i].votes < min && !candidates[i].eliminated)
        {
            min = candidates[i].votes;
        }
    }

    return min;
}

// Retorna "true" se todos os candidatos ainda elegíveis possuem o mesmo número de votos.
bool is_tie(int min)
{
    for(int i = 0; i < candidate_count; i++)
    {
        if(!candidates[i].eliminated && candidates[i].votes != min)
        {
            return false;
        }
    }

    return true;
}

// Elimina o(s) candidato(s) em último lugar nesta etapa da eleição.
void eliminate(int min)
{
    for(int i = 0; i < candidate_count; i++)
    {
        if(candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }

    return;
}
