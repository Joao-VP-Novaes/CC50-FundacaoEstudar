#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    printf("%i\n", x + y);
    
    long u = get_long("u: ");
    long v = get_long("v: ");
    
    printf("%li\n", u + v);
}