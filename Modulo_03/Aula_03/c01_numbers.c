#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // int-(tipo das variáveis do Array) numbers-(nome do Array) [] = {(itens do Array separados por vírgula)}.
    int numbers[] = {4, 6, 8, 2, 7, 5, 0};

    for(int i = 0; i < 7; i++)
    {
        if(numbers[i] == 0)
        {
            printf("Encontrado !\n");

            // Tudo certo.
            return 0;
        }
    }

    printf("Não encontrado.\n");

    // Algo deu errado.
    return 1;
}
