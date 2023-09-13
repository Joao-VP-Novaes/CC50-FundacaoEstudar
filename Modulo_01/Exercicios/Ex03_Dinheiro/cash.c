#include <cs50.h>
#include <stdio.h>
#include <math.h>  // Biblioteca onde se encontra a função round.

// Prototype
int get_value(void);

int main(void)
{
    int divida = get_value();
    int quantMoedas = 0;       // Variável que representa o total de moedas.

    // Nome das moedas.
    int penny = 0;          // 1 centavo
    int nickle = 0;         // 5 centavos
    int dime = 0;           // 10 centavos
    int quarter = 0;        // 25 centavos

    /* Loop onde o valor da dívida é reduzida até chegar em 0, atualizando o total de moedas usadas
     * e a quantidade de cada moeda que é utilizada.
     */
    while (divida > 0)
    {
        if (divida - 25 >= 0)
        {
            divida -= 25;
            quarter++;
        }
        else if (divida - 10 >= 0)
        {
            divida -= 10;
            dime++;
        }
        else if (divida - 5 >= 0)
        {
            divida -= 5;
            nickle++;
        }
        else
        {
            divida -= 1;
            penny++;
        }

        quantMoedas++;
    }

    printf("\nMoedas utilizadas: %i\n", quantMoedas);
    printf("Quantidade de Pennies usadas: %i\n", penny);
    printf("Quantidade de Nickles usadas: %i\n", nickle);
    printf("Quantidade de Dimes usadas: %i\n", dime);
    printf("Quantidade de Quarters usadas: %i\n", quarter);
}

// Função que pede ao usuário um valor em dólares e o converte em centavos.
int get_value(void)
{
    float valorDevido;

    do
    {
        valorDevido = get_float("Troco devido em dólares: ");
    }
    while (valorDevido <= 0);

    int cents = round(valorDevido * 100); // round arredonda o valor com segurança para evitar truncamentos.
    return cents;
}