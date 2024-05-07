#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Função que imprime uma string no console.
    printf("Hello, World !!\n");

    string answer = get_string("What's your name ? ");
    
    // Saudações ao usuário.
    printf("Hello, %s \n", answer);
}