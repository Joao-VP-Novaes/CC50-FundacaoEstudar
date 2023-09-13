#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int init;          // Variável que representa a quantidade inicial de indivíduos.
    int fin;           // Variável que representa a quantidade final de indivíduos.
    int anos = 0;      // Variável que representa o total de anos para a população ir do valor inicial ao final.

    // Coleta o inicial valor de indivíduos.
    do
    {
        init = get_int("Digite a população inicial. Lembre-se que esse cálculo só funciona com 9 ou mais indivíduos: ");
    }
    while (init < 9);

    // Coleta o final valor de indivíduos.
    do
    {
        fin = get_int("Digite a população final. Ela deve ser igual ou maior que a população inicial: ");
    }
    while (fin < init);

    // Variável que representa a variação da população ao longo do tempo.
    int populacao = init;

    if (fin == init)
    {
        printf("\nA população já tem a quantidade final de indivíduos.\n");
    }
    else
    {
        while (populacao < fin)
        {
            // Calculo da variação da população ao longo do tempo.
            populacao += (populacao / 3) - (populacao / 4);
            anos++;
        }
    }

    printf("\nPopulação inicial: %i\n", init);
    printf("População final buscada: %i\n", fin);
    printf("População ao final de %i ano(s): %i\n", anos, populacao);
}