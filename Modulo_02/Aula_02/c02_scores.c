#include <stdio.h>
#include <cs50.h>

float media(int length, int array[]);

int main(void)
{
    // Constantes devem ser declaradas e inicializadas na mesma linha e não podem ter seus valores alterados.
    // Por convenção, nomes de constantes devem ter todas as letras maiúsculas.
    const int TOTAL = 3;

    int scores[TOTAL];

    // Usando um laço para coletar as notas do usuário.
    for (int i = 0; i < TOTAL; i++)
    {
        scores[i] = get_int("Digite uma nota: ");
    }

    printf("Média: %.2f\n", media(TOTAL, scores));
}

// Função para calcular a média dos números de um Array.
// A variável de nome "array" não precisa necessariamente se chamar assim.
float media(int length, int array[])
{
    int soma = 0;

    for (int i = 0; i < length; i++)
    {
        soma += array[i];
    }

    return (float)soma / length;
}