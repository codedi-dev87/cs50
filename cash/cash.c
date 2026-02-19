#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Solicitar ao usuário o troco devido, em centavos.
    int cents;
    do
    {
        cents = get_int("Troco devido: ");
    }
    while (cents < 0);

    // calcular moedas de 25 -> "a"
    int a = cents / 25;
    // atualizar valor restante -> "ra"
    int ra = cents - (a * 25);

    // calcular moedas de 10 -> "b"
    int b = ra / 10;
    // atualizar valor restante ->rb
    int rb = ra - (b * 10);

    // calcular moedas de 5 -> "c"
    int c = rb / 5;
    // atualizar valor restante -> "rc"
    int rc = rb - (c * 5);

    // moedas de 1 -> "d"
    int d = rc;

    // somar todas
    int troco = a + b + c + d;

    // Imprima essa soma.
    printf("%i\n", troco);
}
