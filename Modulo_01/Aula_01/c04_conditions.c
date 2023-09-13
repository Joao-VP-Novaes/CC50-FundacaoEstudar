#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");
    
    if(x > y)
    {
        printf("x is bigger than y.\n");
    } 
    else if(y > x)
    {
        printf("y is bigger than x.\n");
    } 
    else
    {
        printf("x is equal to y.\n");
    }
}