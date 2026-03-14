#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int k);

int main(int argc, string argv[])
{
    // Certificar de que o programa foi executado com apenas um argc.
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Chamar a função only_digits
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Converta argv[1] de uma 'string' para um 'int'
    int k = atoi(argv[1]);

    // Solicite ao usuário o texto simples
    string text = get_string("plaintext:  ");

    // Imprimir "ciphertext
    printf("ciphertext: ");

    // Loop no texto e chamar rotate
    for (int i = 0; text[i] != '\0'; i++)
    {
        printf("%c", rotate(text[i], k));
    }
    printf("\n");
    return 0;
}

// Certifique-se de que cada caractere em argv[1] seja um dígito
bool only_digits(string s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

// Função rotate
char rotate(char c, int k)
{
    // Se for maiúscula.
    if (isupper(c))
    {
        return (c - 'A' + k) % 26 + 'A';
    }
    // Se for minúscula.
    else if (islower(c))
    {
        return (c - 'a' + k) % 26 + 'a';
    }
    // Se for outra coisa(. ! ? , etc.)
    else
    {
        return c;
    }
}
