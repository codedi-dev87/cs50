#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Solicite o valor inicial ao usuário
    int i;
    do
    {
        i = get_int("Tamanho Inicial: ");
    }
    while (i < 9);

    // TODO: Solicite o valor final ao usuário
    int f;
    do
    {
        f = get_int("Tamanho Final: ");
    }
    while (f < i);

    // TODO: Calcule o número de anos até o limite

    int a = 0;

    while (i < f)
    {
        i = i + (i / 3) - (i / 4);
        a++;
    }

    printf("Years: %i\n", a);
}
