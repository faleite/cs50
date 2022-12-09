# Algoritimos

## Algoritmos que resolvem problemas com arrays
- Lembre-se de que os arrays são indexados por zero, o que significa que o primeiro\
item tem um índice de 0. E com **n** itens, o maior índice seria **n-1**.

## Big *O*  (eficiêcia do algoratimof)
- Algoritmos de pesquisa. Para comparar sua eficiência, consideraremos\
o **tempo de execução** ou quanto tempo um algoritmo leva para ser executado,\
dado algum tamanho de entrada.
- alguns tempos de execução comuns:
    - O(n2)
    - O(n log n)
    - O(n)
    - O(log n)
    - O(1)
- Big *O* descreve um limite superior
- Omêga descreve um limite inferior
- Big Theta para quando o limite superior é o mesmo que o inferior

### Pesquisa linear
```c
// Pesquisa de int
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
```

```c
// código de pesquisa linear
 #include <cs50.h>
 #include <stdio.h>
 #include <string.h>

 int main(void)
 {
    // names é uma matriz, e seu tamanho é classificado de acordo
    // ...com o que há entre as chaves {}
    string names[] = {"Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"};

    // percorre item a item por toda a matriz
    for (int i = 0; i < 7; i++)
    {
        // Não podemos comparar strings diretamente em C
        // ...pois não é um tipo embutido na linguagem
        // string é uma matriz de muitos caracteres
        // para comparar strings usamos a função strcmp
        // ...da biblioteca string.h
        if (strcmp(names[i], "Ron") == 0)
        {
            // se encontrado imprima
            printf("Found\n");
            // indica sucesso
            return 0;
        }
    }
    // Após passar por todas a matriz verifincado se há a string "Ron"
    // retornamos 1, para indicar um código de erro
    printf("Not found\n");
    return 1;
 }
```
