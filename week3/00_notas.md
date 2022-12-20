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

## Estrutura de dados
- Em **C**, podemos definir nossos próprios tipos de dados
- Podemos criar uma **struct** com a seguinte sintaxe:
```c
// typedef é uma palavra reservada que define um novo tipo de dados
// struct palavra chave que informa ao compilador que este não é apenas
// ...tipo simples de dados, mas uma estrutura que contém várias coisas
typedef struct
{
    string name;
    string number;
}
person;  // Definição do nome do tipo de dados
```

*Exemplo com código:*
```c
// Uso de arrays (matrizes) com nomes e numeros
// Será usados strings para nomes e numeros
#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[2];

    // .name significa ir dentro da estrutura people
    // ...e acessar a variavel name e dar o nome de "Carter"
    people[0].name = "Carter";
    people[0].number = "+1-617-495-1000";

    people[0].name = "David";
    people[0].number = "+1-949-468-2750";

    // Modo sem typedef
    // string names[] = {"Carter", "David"};
    // string number[] = {"+1-617-495-1000", "+1-949-468-2750"};

    // Procurar por nome e numero na lista
    for (int i = 0; i < 2; i++)
    {
        // comparação (strcmp). Se nome for igual a "David"
        if (strcmp(people[i].name, "David") == 0)
        {
            // imprima o numero e retorne 0 (finalisa sem erros)
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    // imprima "not found" e retorne 1 (Finalisa com erro)
    printf("Not found\n");
    return 1;
}
```

- Na ciência da computação, o **encapsulamento** é a ideia de que os dados\
relacionados são agrupados, e aqui encapsulamos duas informações *name* e *number*\
na mesma estrutura de dados. A cor de um pixel, com valores de vermelho, verde\
e azul, também pode ser bem representada por uma estrutura de dados.
- Também podemos imaginar que um struct pode ser usado para armazenar valores\
decimais precisos ou valores inteiros grandes, talvez com arrays que podemos\
usar para armazenar um grande número de dígitos.

## Ordenação
- Formas de Ordenação:
    - **selection sort**
    - **bubble sort**
    - **recursion**
    - **merge sort**

### Selection sort
*Pseúdo-código*
```c
Para i de 0 a n–1
     Encontre o menor número entre os números[i] e os números[n-1]
     Troque o menor número por números[i]
```

### Bubble sort
*Pseúdo-código*
```c
Repetir n-1 vezes
     Para i de 0 a n–2
         Se números[i] e números[i+1] fora de ordem
             trocá-los
     Se não houver trocas
         Desistir
```

### Recursion
*Pseúdo-código*
```c
Se não houver portas
     Retorna falso
Se o número atrás da porta do meio
     Retorna verdadeiro
Else if número < porta do meio
     Pesquisar metade esquerda
Else if número > porta do meio
     Pesquisar metade direita
```

*código*
```c
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
    draw(n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
```
### Em suma
- A classificação por seleção itera pelas partes não classificadas de uma lista,\
selecionando o menor elemento a cada vez e movendo-o para o local correto.
- A classificação por bolhas compara pares de valores adjacentes um de cada vez e\
os troca se estiverem na ordem incorreta. Isso continua até que a lista seja\
classificada.
- A classificação por mesclagem divide recursivamente a lista em duas repetidamente\
e, em seguida, mescla as listas menores de volta em uma maior na ordem correta.
