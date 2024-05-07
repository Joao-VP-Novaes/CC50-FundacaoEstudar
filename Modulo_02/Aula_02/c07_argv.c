#include <stdio.h>
#include <cs50.h>

// argc => argument count. É um inteiro que representa o número de palavras que o usuário vai digitar no prompt.
// argv => argument vector. É uma variável que vai armazenar em um Array todas as strings que o usuário vai
// digitar no prompt, inclusive nome do programa.
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("Hello, %s\n", argv[1]);
    }
    else
    {
        printf("Hello World !!\n");
    }
}