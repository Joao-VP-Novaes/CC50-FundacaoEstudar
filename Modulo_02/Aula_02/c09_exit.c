#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Faltou um argumento de linha de comando.\n");
        return 1;                                           // 1 nesse programa significa que algo deu errado.
    }

    printf("Hello, %s\n", argv[1]);
    return 0;                                               // 0 nesse programa significa que nada deu errado.
}