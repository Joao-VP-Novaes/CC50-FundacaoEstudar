#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Hello, World !!\n");

    string answer = get_string("What's your name ? ");
    
    // Saudações ao usuário.
    printf("Hello, %s \n", answer);
}