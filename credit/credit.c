#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Solicitar um número para o usuário.
    long n;

    n = get_long("Número: ");

    // Fazer uma cópia do número, para manter guardado o "n".
    long temp = n;

    // Início
    int pos = 1;
    int soma = 0;

    // Loop enquanto "temp" > 0.
    while (temp > 0)
    {
        int dig = temp % 10;

        // Se "pos" for par:
        if (pos % 2 == 0)
        {
            // multiplicar dig por 2 ,
            int produto = dig * 2;

            // Produto menor que 10, acresceta direto à "soma".
            if (produto < 10)
            {
                soma = soma + produto;
            }

            // Produto > 10, soma os dígito e depois acrescenta a "soma".
            else
            {
                // (penúltimo dígito) + (último dígito) + (soma)
                soma += (produto / 10) + (produto % 10);
            }
        }
        // Se "pos" impar: adiciona dig direto à "soma".
        else
        {
            soma = soma + dig;
        }

        temp = temp / 10;
        pos++;
    }

    // Verificar se o cartão é válido.
    if (soma % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Verificar a quantidade de dígitos
    int qd = pos - 1;

    // Descobrir os dígitos iniciais.

    long start = n;

    while (start >= 100)
    {
        start = start / 10;
    }

    // verificar se é AMEX, MASTER, VISA, OU INVÁLIDO.

    // American Express
    if (qd == 15 && (start == 34 || start == 37))
    {
        printf("AMEX\n");
    }

    // MasterCard.
    else if (qd == 16 && (start >= 51 && start <= 55))
    {
        printf("MASTERCARD\n");
    }

    // Visa.
    else if ((qd == 13 || qd == 16) && (start / 10 == 4))
    {
        printf("VISA\n");
    }

    // Inválido.
    else
    {
        printf("INVALID\n");
    }
}
