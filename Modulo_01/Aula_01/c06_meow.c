#include <stdio.h>

//Prototype
void meow(void);
void miau(int vezes);

int main(void)
{
    for (int i = 0; i < 5; i++)
    {
        meow();
    }
    
    miau(3);
}

void meow(void)
{
    printf("meow\n");
}

void miau(int vezes)
{
    for (int i = 0; i < vezes; i++)
    {
        printf("miau\n");
    }
}