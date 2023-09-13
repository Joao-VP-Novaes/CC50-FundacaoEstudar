#include <stdio.h>
#include <cs50.h>

// Prototype
int get_height(void);

int main(void)
{
    int altura = get_height();
    int decre = altura - 1;     // Decremento
    int incre = 1;              // Incremento

    // Construção da pirâmide.
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

        decre--;
        incre++;
        printf("\n");
    }
}

int get_height(void)
{
    int height;

    // Pede a altura da pirâmide ao usuário.
    do
    {
        height = get_int("Digite a altura da pirâmide (valor inteiro de 1 a 8): ");
    }
    while (height < 1 || height > 8);

    return height;
}