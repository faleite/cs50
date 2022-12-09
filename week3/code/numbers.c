// código de pesquisa linear
// Big O -> O(n)
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // numbers é uma matriz, e seu tamanho é classificado de acordo
    // ...com o que a entre as chaves {}
    int numbers[] = {4, 6, 8, 2, 7, 5, 0};

    // percorre item a item por toda a matriz
    for (int i = 0; i < 7; i++)
    {
        // busca pelo o numero zero dentro da matriz
        // Teste também com um número que não esteja na matriz
        if (numbers[i] == 0)
        {
            // se encontrado imprima
            printf("Found\n");
            // indica sucesso
            return 0;
        }
    }
    // Após passar por todas a matriz verifincado se há o número 0
    // retornamos 1, para indicar um código de erro
    printf("Not found\n");
    return 1;
}
