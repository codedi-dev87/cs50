#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Pontos para cada letra em ordem alfabética.
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Função compute_score.(Recebe a palavra word).
int compute_score(string word);

// Main
int main(void)
{
    // Pedir palavra do jogador 1
    string word1 = get_string("Player 1: ");

    // Pedir palavra do jogador 2
    string word2 = get_string("Player 2: ");

    // Calcular score1 usando compute_score
    int score1 = compute_score(word1);

    // Calcular score2 usando compute_score
    int score2 = compute_score(word2);

    // Comparar score1 e score2 e imprimir o vencedor.
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }

    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }

    else
    {
        printf("Tie!\n");
    }
}

// Começar a função
int compute_score(string word)
{
    // Criar variável score = 0
    int score = 0;

    // Calcular a pontuação para cada caractere com loop for
    for (int i = 0; word[i] != '\0'; i++)
    {
        // letras maiusculas e minusculas
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }

        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }
    // retornar score.
    return score;
}
