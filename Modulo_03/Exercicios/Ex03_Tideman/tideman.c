#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Número máximo de candidatos.
#define MAX 9

// preferences[i][j] é o número de eleitores que preferem i a j.
int preferences[MAX][MAX];

// locked[i][j] significa que há uma aresta de i para j.
bool locked[MAX][MAX];

// Cada par tem um vencedor(winner) e um perdedor(loser).
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array de candidatos.
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool cycle_check(int current, int original);


int main(int argc, string argv[])
{
    // Checa por uso incorreto.
    if (argc < 2)
    {
        printf("Uso: ./tideman [candidato ...]\n");
        return 1;
    }

    // Preenche o array de candidatos.
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("O número máximo de candidatos é: %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Preenche todos os campos de locked[][] com false.
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Número de eleitores: ");

    // Para cada candidato.
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] é a (i)ésima preferência do candidato.
        int ranks[candidate_count];

        // Pede pelos votos.
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Voto inválido.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Atualiza ranks[] dado um novo voto.
bool vote(int rank, string name, int ranks[])
{
    for(int i = 0; i < candidate_count; i++)
    {
        if(!(strcmp(candidates[i], name)))
        {
            ranks[rank] = i;
            return true;
        }
    }

    return false;
}

// Atualiza o array de preferences dado um novo voto.
void record_preferences(int ranks[])
{
    for(int i = 0; i < (candidate_count-1); i++)
    {
        int like = ranks[i];

        for(int j = i+1; j < candidate_count; j++)
        {
            int dislike = ranks[j];

            preferences[like][dislike]++;
        }
    }

    return;
}

// Atualiza o array pairs[] com um vencedor e um perdedor e a variável pair_count.
void add_pairs(void)
{
    for(int i = 0; i < (candidate_count-1); i++)
    {
        for(int j = i+1; j < candidate_count; j++)
        {
            if(preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if(preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }

    return;
}

// Organiza os pares em ordem decrescente de força de vitória.
void sort_pairs(void)
{
    int forca[pair_count];

    for(int i = 0; i < pair_count; i++)
    {
        forca[i] = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
    }

    while(true)
    {
        int alteracoes = 0;
        int auxForca;
        pair auxPair;

        for(int i = 0; i < (pair_count-1); i++)
        {
            if(forca[i] < forca[i+1])
            {
                auxForca = forca[i+1];
                forca[i+1] = forca[i];
                forca[i] = auxForca;

                auxPair = pairs[i+1];
                pairs[i+1] = pairs[i];
                pairs[i] = auxPair;

                alteracoes++;
            }
        }

        if(alteracoes == 0)
        {
            break;
        }
    }

    return;
}

// Atualiza o array locked[][] em ordem e sem criar ciclos.
void lock_pairs(void)
{
    for(int i = 0; i < pair_count; i++)
    {
        if(!cycle_check(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
}

// Exibe o vencedor da eleição.
void print_winner(void)
{
    for(int i = 0; i < candidate_count; i++)
    {
        bool defeated = false;

        for(int j = 0; j < candidate_count; j++)
        {
            if(locked[j][i] == true)
            {
                defeated = true;
                break;
            }
        }

        if(!defeated)
        {
            printf("%s\n", candidates[i]);
        }
    }

    return;
}

// Procura por arestas que possam criar ciclos no grafo.
bool cycle_check(int current, int original)
{
    for(int i = 0; i < candidate_count; i++)
    {
        if(locked[current][i])
        {
            if(i == original)
            {
                return true;
            }
            else if(cycle_check(i, original))
            {
                return true;
            }
        }
    }

    return false;
}
