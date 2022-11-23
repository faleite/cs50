/* Arrays (Matrizes) */
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Podemos armazenar várias pontuações em uma array
    int scores[3];  // aqui temos 3 valores armazenados

    // O primeiro valor sempre sera armazenado em "0"
    scores[0] = 72;
    scores[1] = 72;
    scores[2] = 33;

    // Aqui há um calculo da média dos três valores
    // Sabemos que o resultado sera um float, mas os valores declarados são int
    // Para retornar um valor float basta tornar apenas um dos valores em float
    // e todos os outros valores serão tratados como float.
    // Aqui tranformamos o 3 float (3.0)
    printf("Average: %f\n", (scores[0] + scores[1] + scores[2] / 3.0));
}


/* Mesmo código com melhor design e mais sucinto */
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = get_int("How many scores? ");

    int scores[n];

    for (int i = 0; i < n; i++)
    {
      scores[i] = get_int("Score: ");
    }

    printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
}
