#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Pontos associados a cada letra do alfabeto em ordem.
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Prototype
int compute_score(string word);

int main(void)
{
    // Coleta as palavras de ambos os jogadores.
    string word1 = get_string("Jogador 1: ");
    string word2 = get_string("Jogador 2: ");

    // Variáveis que armazenam os pontos das palavras
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Exibe os pontos de cada jogador.
    printf("\nJogador 1: %i pontos.\nJogador 2: %i pontos.\n\n", score1, score2);

    // Informa quem venceu.
    if(score1 > score2)
    {
        printf("O jogador 1 venceu !\n");
    }
    else if(score2 > score1)
    {
        printf("O jogador 2 venceu !\n");
    }
    else
    {
        printf("Empate !\n");
    }
}

// Função responsável por determinar o quanto uma palavra pontua.
int compute_score(string word)
{
    int totalPoints = 0;

    for(int i = 0, len = strlen(word); i < len; i++)
    {
        if(isalpha(word[i]) && islower(word[i]))
        {
            int aux = word[i] - 97;
            totalPoints += POINTS[aux];
        }
        else if(isalpha(word[i]) && isupper(word[i]))
        {
            int aux = word[i] - 65;
            totalPoints += POINTS[aux];
        }
    }

    return totalPoints;
}
