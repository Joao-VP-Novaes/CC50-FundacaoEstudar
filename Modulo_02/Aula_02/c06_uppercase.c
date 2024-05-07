#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = get_string("Antes: ");

    // Opção 01
    printf("Depois: ");

    for (int i = 0, n= strlen(s); i < n; i++)
    {
        if (islower(s[i]))                  // islower() Retorna true se o parâmetro for uma letra minúscula.
        {
            printf("%c", toupper(s[i]));    // toupper() converte o parâmetro, um caractere, para uma letra maiúscula, se for possível.
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");

    // Opção 02
    printf("Depois: ");

    for (int i = 0, n = strlen(s); i < n; i++)
    {
       printf("%c", toupper(s[i]));
    }
    printf("\n");
}