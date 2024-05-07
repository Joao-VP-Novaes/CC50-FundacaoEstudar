#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string s = get_string("Antes: ");
    printf("Depois: ");

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')     // O que é considerado nessas comparações são os códigos da tabela ASCII.
        {
            printf("%c", s[i] - 32);        // Convertendo uma letra de minúscula para maiúscula pela tabela ASCII.
        }
        else
        {
            printf("%c", s[i]);
        }
    }

    printf("\n");
}