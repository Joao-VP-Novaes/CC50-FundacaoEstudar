#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float x = get_float("x: ");
    float y = get_float("y: ");

    // .10 representa a quantidade de casas decimais que serão impressas. Outros números inteiros poderiam estar no lugar do 10.
    printf("%.10f\n", x / y);
}