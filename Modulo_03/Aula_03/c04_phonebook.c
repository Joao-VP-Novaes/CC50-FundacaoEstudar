#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    /* Existe uma alta probabilidade de algo dar errado neste programa, o melhor a se fazer é um
     * código que consiga se proteger de erros cometidos pelo próprio programador ou pelo usuário final.
     */

    string names[] = {"Brian", "David"};
    string numbers[] = {"+1-671-119-8000", "+1-889-549-1000"};

    for(int i = 0; i < 2; i++)
    {
        if(strcmp(names[i], "David") == 0)
        {
            printf("Found %s\n", numbers[i]);
            return 0;
        }
    }

    printf("Not found\n");
    return 1;
}
