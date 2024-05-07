#include <cs50.h>
#include <stdio.h>
#include <math.h>  // Biblioteca onde está a função round().
#include <ctype.h> // Biblioteca onde está a função isalpha().
#include <string.h>

// Prototype.
int findGrade(int nLetters, int nWords, int nPhrases);

int main(void)
{
    // Entrada de texto do usuário.
    string texto = get_string("Texto: ");

    int numLetras = 0;      // Número de letras.
    int numPalavras = 1;    // Número de palavras.
    int numFrases = 0;      // Número de frases.

    for (int i = 0, len = strlen(texto); i < len; i++)
    {
        if (isalpha(texto[i]))
        {
            numLetras++;
        }
        else if (isspace(texto[i]))
        {
            numPalavras++;
        }
        else if (texto[i] == '!' || texto[i] == '.' || texto[i] == '?')
        {
            numFrases++;
        }
    }

    // Variável onde a "Grade" do texto é armazenada.
    int grade = findGrade(numLetras, numPalavras, numFrases);

    if (grade < 16 && grade > 0)
    {
        printf("Grade: %i\n", grade);
    }
    else if (grade <= 0)
    {
        printf("Antes da Grade 1.\n");
    }
    else
    {
        printf("Grade 16+\n");
    }

    printf("\nNúmero de letras: %i\n", numLetras);
    printf("Número de palavras: %i\n", numPalavras);
    printf("Número de frases: %i\n", numFrases);
}

// Função responsável por determinar a "Grade" do texto.
int findGrade(int nLetters, int nWords, int nPhrases)
{
    float L = (100 * nLetters) / nWords;
    float S = (100 * nPhrases) / nWords;

    // Fórmula do índice Coleman-Liau.
    int indice = round((0.0588 * L) - (0.296 * S) - 15.8);

    return indice;
}