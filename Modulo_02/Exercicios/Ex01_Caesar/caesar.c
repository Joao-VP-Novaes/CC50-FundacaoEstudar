#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> // Biblioteca onde estão as funções isalpha(), isupper() e islower().
#include <stdlib.h> // Biblioteca onde está a função atoi().

// Prototype
int cyfer(string text, int key);

int main(int argc, string argv[])
{
    // Verificação se a contagem de argumentos está correta.
    if (argc != 2)
    {
        printf("Forma de usar: ./caesar chave\n");
        return 1;
    }

    // Verificação se o usuário forneceu uma chave(número) válida.
    for(int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if(!(isdigit(argv[1][i])))
        {
            printf("Forma de usar: ./caesar chave\n");
            return 1;
        }
    }

    // Variável onde a chave é armazenada após ser convertida para inteiro pela função atoi().
    // atoi é abreviação de "ASCII to Integer" (ASCII para inteiro).
    int key = atoi(argv[1]);

    // Variável onde é armazenado o texto a ser criptografado.
    string text = get_string("Texto simples: ");

    printf("Texto cifrado: ");

    // Chamada da função cyfer()
    cyfer(text, key);
}

// Função responsável por criptografar um texto e exibi-lo na tela.
int cyfer(string text, int key)
{
    for(int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]) && islower(text[i]))
        {
            // Criptografando uma letra minúscula.
            char c = (text[i] - 97 + key) % 26;
            printf("%c", c + 97);
        }
        else if (isalpha(text[i]) && isupper(text[i]))
        {
            // Criptografando uma letra maiúscula.
            char c = (text[i] - 65 + key) % 26;
            printf("%c", c + 65);
        }
        else
        {
            // Exibindo um caractere que não é uma letra.
            printf("%c", text[i]);
        }
    }

    printf("\n");
    return 0;
}