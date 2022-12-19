# Recursion
## Recurção
- A recurção resolve problemas de maneiras interessantes, curtas e fáceis de\
visualizar
- A recurção é definida como uma função que chama a si mesma como parte de sua\
execução.

### Definição de um procedimento recursivo
- Funçao fatorial, denotada na matemática como **n!**, que é definido sobre\
todos os números inteiros positivos. A maneira que n fatorial é calculado, é\
você multiplicar todos os números menores ou igual a todos os n juntos, Então\
5 fatorial é 5 vezes 4, vezes 3, vezes 2 vezes 1.
- Na programação o fatorial é denotado como **fact(n)** em vez de **n!** como\
na matemática.
    - Exemplo de fatorial:
        - fact(1) = 1
        - fact(2) = 2 * 1 ---> *mesmo que: 2 * fact(1)*
        - fact(3) = 3 * 2 * 1 ---> *mesmo que: 3 * fact(2)*
        - fact(4) = 4 * 3 * 2 * 1 ---> *mesmo que: 4 * fact(3)*
        - fact(5) = 5 * 4 * 3 * 2 * 1 ---> *mesmo que: 5 * fact(4)*
        - ...
    - Podemos generalizar a função fatorial como:
        - n vezes o fatorial de n-1. (É n vezes o produto de todos os números\
        menores que eu)
            - fact(n) = n * fact(n-1)

***Quando você define uma função recursivamente, há duas coisas que precisam fazer\
parte dela.***
1. **Base Case**
    - Você precisa ter algo chamado **base case**, que ao ser acionado, interromperá\
    o processo recursivo. Caso contrário, uma função que chama a si mesma poderia\
    durar para sempre. Está é uma solução simples para um problema que impede a\
    ocorrêcia do processo recursivo.
    - **fact(1)** é um bom caso para ser o **base case**, o fact(1) é apenas 1, e\
    simplemente podemos resolver este problema de parar a recursão em algum lugar,\
    pois provavelmente queremos pará-la quando chegarmos a 1.
2. **Recursive Case**
    - É aqui que a recurção realmente ocorrerá. É aqui que a função chamará a si\
    mesma.

***Para fazermos uma função recursiva, precisamos conectar essas duas coisas,\
o Base Case e o Recursive Case.***

### Forma Recursiva
```c
int fact(int n)
{
    // base case
    // se n for igual a 1 retorne 1
    if (n == 1)
    {
        return 1; 
    }
    // recursive case
    // se não estamos olhando para 1
    else
    {
        return n * fact(n-1);
    }
}
```
*Forma mais limpa e curta:*
```c
int fact(int n)
{
    if (n == 1)
        return 1; 

    else
        return n * fact(n-1);
}
```
***Em geral, mas nem sempre, uma função recursiva pode substituir um loop em\
uma função não recursiva.***

### Forma Interativa
*Versão iterativa da função fatorial:*
```c
int fact2(int n)
{
    int product = 1;
      while (n > 0)
    {
        product *= n;
        n--;
    }
    return product;
}
```
***Ambas as formas (recursiva e interativa) calculam o fatorial de n.***

## Multiplos casos base e multiplos casos recursivos

### Multiplo caso base

- Dependendo da função que precisa fazer, é possivel ter mais de um **base case**\
ou mais de um **recursve case**
- Você não esta limitado a um único *base case* ou um único *recursive case*
- Exemplo de multiplo base case: *Sequência de Fibonacci*
    - O primeiro elemento é 0. (por definição)
    - O segundo elemento é 1. (por definição)
    - Em seguida, todos os outros elementos são definidos como a soma de (n-1)\
    e (n-2).
    - Nesse caso, temos dois *base case*:
        - Se n for igual a 1, retorne 0.
        - Se n for igual a 2, retorne 1.
        - Caso contrário. retorne Fibonnaci de (n-1) mais Fibonacci de (n-2).

### Multiplo caso recursivo
- Exemplo de multiplo recursive case: *Collatz*
    - Ele se aplica a todo elemento inteiro positivo
    - E especula que é sempre possível voltar a **1** se seguir os seguintes passos:
        - Se **n** for **1**, pare.
        - Caso contrário repita este processo em (n/2), e veja se consegue voltar a 1
        - Caso contrário, se n for ímpar, repita este processo em (3*n + 1)
- Exemplo de resultados:

n|collatz(n)|Steps|
-|----------|-----|
1|0|1
2|1|2 -> 1
3|7|3 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
4|2|4 -> 2 -> 1
...

- Exemplo com código:
```c
#include <stdio.h>
#include <cs50.h>

int collatz(int n);

int main(void)
{
    int integer = get_int("Integer: ");

    int result = collatz(integer);

    printf("collatz(integer): %i\n", result);
}

int collatz(int n)
{
    // base case
    if (n == 1)
    {
        return 0;
    }
    // even numbers
    else if (n % 2 == 0)
    {
        return 1 + collatz(n/2);
    }
    // odd numbers
    else
    {
        return 1 + collatz(3*n + 1);
    }
}
```

