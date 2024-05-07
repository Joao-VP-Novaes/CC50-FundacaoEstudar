#include <cs50.h>
#include <stdio.h>
#include <string.h> // Biblioteca onde está a função strcmp()

int main(void)
{
    string names[] = {"Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"};

    for(int i = 0; i < 7; i++)
    {
        // if(names[i] == "Ron");    Em C, não podemos comparar strings com (==).

        // strcmp() recebe duas strings por parâmetro e retorna 0 se os conteúdos delas forem iguais,
        // um valor negativo se a primeira string vem asciibeticamente antes da segunda ou um valor positivo
        // se a segunda string vem asciibeticamente antes da primeira.
        if(strcmp(names[i], "Ron") == 0)
        {
            printf("Encontrado.\n");
            return 0;
        }
    }

    printf("Não encontrado.\n");
    return 1;
}
