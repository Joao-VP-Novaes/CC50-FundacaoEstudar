#include <stdio.h>
#include <cs50.h>
#include <string.h> // Biblioteca onde está a função strlen()

int main(void)
{
    string s = get_string("Entrada: ");
    printf("Saída: ");

    // '\0' é o caractere nulo. Ele representa um Byte composto por 8 bits de 0. As Strings em C terminam com esse caractere.
    for (int i = 0; s[i] != '\0'; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");

    printf("Saída 2: ");

    // strlen() é uma função que retorna o tamanho da string passada por parâmetro.
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}