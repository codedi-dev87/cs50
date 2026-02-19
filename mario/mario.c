#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    // Solicita ao usuário um número inteiro entre 1 e 8
    do
    {
        n = get_int("Altura: ");
    }

    while (n < 1 || n > 8);

    // Loop para cada linha da pirâmide (1 até n)
    for (int i = 1; i <= n; i++)
    {
        // Imprimir os espaços para alinhar à direita
        for (int p = 0; p < n - i; p++)
        {
            printf(" ");
        }
        // Imprimir os blocos (#)
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        // Pular uma linha
        printf("\n");
    }
}
