#include <stdio.h>
#include <cs50.h>

int get_positive_int(void);

int main(void)
{
    int i = get_positive_int();
    printf("O número digitado foi: %i\n", i);
}

// Prompt the user for a positive integer
int get_positive_int(void)
{
    int num; // Escopo visível na função inteira.
    
    do
    {
        // Programa reconhece que num é a variável criada anteriormente e modifica ela.
        num = get_int("Digite um inteiro positivo: "); 
    }
    while(num <= 0);
    return num;
}