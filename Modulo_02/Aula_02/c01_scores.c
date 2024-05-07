#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int score1 = 72;
    int score2 = 73;
    int score3 = 33;

    printf("Média truncada: %i\n", (score1 + score2 + score3) / 3); // Truncate.
    printf("Média precisa: %.2f\n", (score1 + score2 + score3) / 3.0);

    printf("\n/// Utilizando Arrays ///\n");

    // int-(tipo das variáveis do Array) scores-(nome do Array) [3-(tamanho do Array)].
    int scores[3];

    scores[0] = get_int("Primeira nota: ");
    scores[1] = get_int("Segunda nota: ");
    scores[2] = get_int("Terceira nota: ");

    printf("Média: %.2f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
}