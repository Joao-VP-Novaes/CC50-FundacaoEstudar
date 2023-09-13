#include <stdio.h>
#include <cs50.h>

int main(void)
{ 
    //Ex. 01:
    int x = get_int("x: ");
    int y = get_int("y: ");
    
    int z = x / y;
    
    printf("%i\n", z);
    
    //Ex. 02:
    int u = get_int("u: ");
    int v = get_int("v: ");
    
    float w = u / z;
    
    printf("%f\n", w);
    
    //Ex. 03:
    int a = get_int("a: ");
    int b = get_int("b: ");
    
    // Conversão explícita. Poderia converter a e b para float sem problemas.
    float c = a / (float)b; 
    
    printf("%f\n", c);
}