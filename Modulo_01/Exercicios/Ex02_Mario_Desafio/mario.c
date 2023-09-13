#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Variável que representa a altura das pirâmides.
    int altura;

    // Pede a altura das pirâmides ao usuário.
    do
    {
        altura = get_int("Digite a altura das pirâmides (valor inteiro de 1 a 8): ");
    }
    while (altura < 1 || altura > 8);

    int incre = 1;              // Incremento
    int decre = altura - 1;     // Decremento

    // Construção das pirâmides.
    for (int a = 0; a < altura; a++)
    {
        for (int i = 0; i < decre; i++)
        {
            printf(" ");
        }

        for (int j = 0; j < incre; j++)
        {
            printf("#");
        }

        printf("  ");

        for (int j = 0; j < incre; j++)
        {
            printf("#");
        }

        incre++;
        decre--;
        printf("\n");
    }
}