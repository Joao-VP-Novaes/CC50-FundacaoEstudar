#include <cs50.h>
#include <stdio.h>
#include <string.h> // Biblioteca onde está a função strcmp()

int main(void)
{
    string names[] = {"Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"};

    for(int i = 0; i < 7; i++)
    {
        // Em expressões booleanas, apenas 0 é false, qualquer outro número é equivalente a true.
        if(!(strcmp(names[i], "ron")))
        {
            printf("Encontrado.\n");
            return 0;
        }
    }

    printf("Não encontrado.\n");
    return 1;
}
