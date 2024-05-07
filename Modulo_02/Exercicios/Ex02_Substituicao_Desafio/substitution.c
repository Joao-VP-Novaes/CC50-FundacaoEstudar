#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int cifra(string plainText, char fixedKey[]);

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Forma de usar: ./substitution chave\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("A chave deve conter 26 caracteres.\n");
        return 1;
    }

    char fixedKey[26];

    for(int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if(!(isalpha(argv[1][i])))
        {
            printf("A chave deve conter apenas caracteres alfabéticos.\n");
            return 1;
        }

        for(int j = 0; j < i; j++)
        {
            if(argv[1][j] == argv[1][i])
            {
                printf("A chave não deve conter caracteres repetidos.\n");
                return 1;
            }
        }

        fixedKey[i] = toupper(argv[1][i]);
    }

    string plainText = get_string("Texto simples: ");

    printf("Texto cifrado: ");

    cifra(plainText, fixedKey);
}


int cifra(string plainText, char fixedKey[])
{
    for(int i = 0, len = strlen(plainText); i < len; i++)
    {
        if(isalpha(plainText[i]) && isupper(plainText[i]))
        {
            int c = plainText[i] - 65;

            printf("%c", fixedKey[c]);
        }
        else if(isalpha(plainText[i]) && islower(plainText[i]))
        {
            int c = plainText[i] - 97;

            printf("%c", fixedKey[c]);
        }
        else
        {
            printf("%c", plainText[i]);
        }
    }

    printf("\n");
    return 0;
}
