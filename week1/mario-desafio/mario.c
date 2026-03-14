#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;

    do
    {
        n = get_int("Altura: ");
    }

    while (n < 1 || n > 8);

    // loop das linhas
    for (int i = 0; i < n; i++)
    {
        int hashes = i + 1;
        int espacos = n - hashes;

        // espaços para alinhar à direira
        for (int s = 0; s < espacos; s++)
        {
            printf(" ");
        }

        // imprime a coluna da esquerda
        for (int h = 0; h < hashes; h++)
        {
            printf("#");
        }

        // vão do meio
        printf("  ");

        // imprime a coluna da direita
        for (int t = 0; t < hashes; t++)
        {
            printf("#");
        }

        // pula uma linha
        printf("\n");
    }

}
