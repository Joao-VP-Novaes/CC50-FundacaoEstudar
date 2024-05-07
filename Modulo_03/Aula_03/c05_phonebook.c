#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Definindo um tipo em C.
typedef struct
{
    // string-(tipo do atributo) name-(nome do atributo).
    string name;
    string number;
}
person; // Nome do tipo.

int main(void)
{
    person people[2];

    // people-(nome do array) [0-(índice do array)] .name-(acessando o atributo name) = "Brian"-(valor dado ao atributo);
    people[0].name = "Brian";
    people[0].number = "+1-671-119-8000";

    people[1].name = "David";
    people[1].number = "+1-889-549-1000";

    for(int i = 0; i < 2; i++)
    {
        if(strcmp(people[i].name, "David") == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }

    printf("Not found\n");
    return 1;
}
