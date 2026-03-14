#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Funções.
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Solicitar ao usuário que insira algum texto.
    string text = get_string("Text: ");

    // Contar o número de letras, palavras e frases.
    int letters = count_letters(text);
    int word = count_words(text);
    int sentences = count_sentences(text);

    // Calcular o índice de Coleman-Liau.
    float L = (float) letters / word * 100;
    float S = (float) sentences / word * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    // Imprimir a série escolar.
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }

    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }

    else
    {
        printf("Grade %i\n", grade);
    }
}

// Função para contar letras.
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

// Função para contar palavras.
int count_words(string text)
{
    int word = 1;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ')
        {
            word++;
        }
    }
    return word;
}

// Função para contar Frases.
int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
