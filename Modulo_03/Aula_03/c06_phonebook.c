#include <cs50.h>
#include <stdio.h>
#include <string.h>


typedef struct
{
    string name;
    string number;
}
person;

const int NUMBER = 5;

int main(void)
{
    person people[NUMBER];

    for(int i = 0; i < NUMBER; i++)
    {
        people[i].name = get_string("Informe o nome: ");
        people[i].number = get_string("Informe o número: ");
    }

    printf("\n");

    for(int i = 0; i < NUMBER; i++)
    {
        printf("%i.: Nome: %s. Número: %s\n", i, people[i].name, people[i].number);
    }
}
