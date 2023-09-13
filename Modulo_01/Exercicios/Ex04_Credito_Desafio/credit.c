#include <cs50.h>
#include <stdio.h>

// Prototype
int firstValid(long number);

int main(void)
{
    // Coletar o número do cartão do usuário.
    long numero = get_long("Digite o número do cartão: ");

    // primeValid (primeira validação) armazena um valor retornado da função firstValid().
    int primeValid = firstValid(numero);

    // Dentro dessas condicionais está o cálculo que descobre se o número está de acordo com o algoritmo de Luhn.
    if (primeValid == 1)
    {
        int soma = 0;
        long init = 100;
        long fin = 10;

        long init2 = 10;
        long fin2 = 1;

        for (int i = 0; i < 7; i++)
        {
            int var = 2 * (((numero % init) - (numero % fin)) / fin);

            init *= 100;
            fin *= 100;

            if (var >= 10)
            {
                var -= 9;
                soma += var;
            }
            else
            {
                soma += var;
            }
        }

        for (int i = 0; i < 8; i++)
        {
            int vari = ((numero % init2) - (numero % fin2)) / fin2;

            init2 *= 100;
            fin2 *= 100;

            soma += vari;
        }

        if (soma % 10 == 0)
        {
            // Cartão com estrutura American Express e de acordo com o algoritmo de Luhn.
            printf("\nAMERICAN EXPRESS\n");
        }
        else
        {
            // Cartão com estrutura American Express mas não de acordo com o algoritmo de Luhn.
            printf("INVALID AMEX\n");
        }
    }
    else if (primeValid == 2)
    {
        int soma = 0;
        long init = 100;
        long fin = 10;

        long init2 = 10;
        long fin2 = 1;

        for (int i = 0; i < 8; i++)
        {
            int var = 2 * (((numero % init) - (numero % fin)) / fin);

            init *= 100;
            fin *= 100;

            if (var >= 10)
            {
                var -= 9;
                soma += var;
            }
            else
            {
                soma += var;
            }
        }

        for (int i = 0; i < 8; i++)
        {
            int vari = ((numero % init2) - (numero % fin2)) / fin2;

            init2 *= 100;
            fin2 *= 100;

            soma += vari;
        }

        if (soma % 10 == 0)
        {
            // Cartão com estrutura MasterCard e de acordo com o algoritmo de Luhn.
            printf("MASTERCARD\n");
        }
        else
        {
            // Cartão com estrutura MasterCard mas não de acordo com o algoritmo de Luhn.
            printf("INVALID MASTERCARD\n");
        }
    }
    else if (primeValid == 3)
    {
        int soma = 0;
        long init = 100;
        long fin = 10;

        long init2 = 10;
        long fin2 = 1;

        for (int i = 0; i < 6; i++)
        {
            int var = 2 * (((numero % init) - (numero % fin)) / fin);

            init *= 100;
            fin *= 100;

            if (var >= 10)
            {
                var -= 9;
                soma += var;
            }
            else
            {
                soma += var;
            }
        }

        for (int i = 0; i < 7; i++)
        {
            int vari = ((numero % init2) - (numero % fin2)) / fin2;

            init2 *= 100;
            fin2 *= 100;

            soma += vari;
        }

        if (soma % 10 == 0)
        {
            // Cartão com estrutura Visa e de acordo com o algoritmo de Luhn.
            printf("VISA\n");
        }
        else
        {
            // Cartão com estrutura Visa mas não de acordo com o algoritmo de Luhn.
            printf("INVALID VISA\n");
        }
    }
    else if (primeValid == 4)
    {
        int soma = 0;
        long init = 100;
        long fin = 10;

        long init2 = 10;
        long fin2 = 1;

        for (int i = 0; i < 8; i++)
        {
            int var = 2 * (((numero % init) - (numero % fin)) / fin);

            init *= 100;
            fin *= 100;

            if (var >= 10)
            {
                var -= 9;
                soma += var;
            }
            else
            {
                soma += var;
            }
        }

        for (int i = 0; i < 8; i++)
        {
            int vari = ((numero % init2) - (numero % fin2)) / fin2;

            init2 *= 100;
            fin2 *= 100;

            soma += vari;
        }

        if (soma % 10 == 0)
        {
            // Cartão com estrutura Visa e de acordo com o algoritmo de Luhn.
            printf("VISA\n");
        }
        else
        {
            // Cartão com estrutura Visa mas não de acordo com o algoritmo de Luhn.
            printf("INVALID VISA\n");
        }
    }
    else
    {
        // Cartão fora das estruturas 
        printf("INVALID\n");
    }
}

// Função que faz a primeira validação para garantir que o número está dentro de uma estrutura aceitável.
int firstValid(long number)
{
    long d13 = 1000000000000;
    long d14 = 10000000000000;
    long d15 = 100000000000000;
    long d16 = 1000000000000000;

    if (number / d14 == 34 || number / d14 == 37)
    {
        // Caso a estrutura esteja de acordo com o cartão American Express.
        return 1;
    }
    else if (number / d15 == 51 || number / d15 == 52 || number / d15 == 53 || number / d15 == 54 || number / d15 == 55)
    {
        // Caso a estrutura esteja de acordo com o cartão MasterCard.
        return 2;
    }
    else if (number / d13 == 4)
    {
        // Caso a estrutura esteja de acordo com o cartão Visa de 13 dígitos.
        return 3;
    }
    else if (number / d16 == 4)
    {
        // Caso a estrutura esteja de acordo com o cartão Visa de 16 dígitos.
        return 4;
    }
    else
    {
        // Caso a estrutura não esteja de acordo com nenhum cartão.
        return 0;
    }
}
