#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';
    string s = "HI!";

    // Imprime os caracteres individualmente.
    printf("%c%c%c\n", c1, c2, c3);

    // Strings só existem em C na biblioteca <cs50.h>
    printf("%s\n", s);

    // Imprime os códigos ASCII dos caracteres, que são inteiros.
    printf("%i %i %i\n", c1, c2, c3);

    // Imprime cada caractere da string "HI!".
    printf("%c%c%c\n", s[0], s[1], s[2]);

    // Imprime os códigos ASCII dos caracteres da string s e do que estiver além na memória do computador.
    printf("%i %i %i %i %i %i %i\n", s[0], s[1], s[2], s[3], s[400], s[572], s[643]);
}