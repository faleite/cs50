// Recursion
// Cria escada descendo da esquerda para a direita
#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main (void)
{
    int height = get_int("Height: ");

    draw(height);
}

// função do tipo void não retorna nada
// neste caso vai apenas imprimir algo
void draw(int n)
{
    // se n for menor ou igual a zero, pare sem imprimir nada
    if (n <= 0)
    {
        return;
    }

    // chama a função de forma recursiva
    //draw(n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
