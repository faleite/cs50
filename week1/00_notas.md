# Estudo da semana 01

## Bibliotecas

*Para usar certos recursos ou funções que não vêm com C, precisamos carregar bibliotecas.
Uma biblioteca é um conjunto comum de código, como extensões, que podemos reutilizar.*

**stdio.h** (Standard input/output ou std i/o)
- se refere a uma biblioteca para funções padrão de entrada e saída.

Com a linha: #include <stdio.h> (.h --> hash)
- estamos carregando essa biblioteca que contém printf, para que possamos imprimir na tela.
- Também chamado de arquivo de cabeçalho (header file)

## Equeleto do bloco de código em C.
```c
int main(void)
{
    // Você pode colocar todo o seu código dentro deste conjunto de chaves
}
```

## Tipos e códigos de formato

### Tipos
- Existem muitos tipos de dados que podemos usar para nossas variáveis,
que indicam ao nosso programa que tipo de dados elas representam:
    - **bool** --> uma expressão booleana de true ou false
    - **char** --> um único caractere como a ou 2
    - **double** --> um valor de ponto flutuante com mais dígitos do que um **float**
    - **float** --> um valor de ponto flutuante ou número real com um valor decimal
    - **int** --> inteiros até um determinado tamanho ou número de bits
    - **long** --> inteiros com mais bits, para que possam contar mais do que um **int**
    - **string** --> uma cadeia de caracteres
    - ...

### Códigos de formato
- Para printf, também existem espaços reservados diferentes para cada tipo,
chamados de códigos de formato:
    - **%c** para caracteres
    - **%f** para floats ou doubles
    - **%i** para ints
    - **%li** para inteiros longos
    - **%s** para strings

### Contador
- Podemos criar uma variável chamada counter e definir seu valor 0:
```c
int counter = 0;
```

- E podemos aumentar o valor com:
```c
counter = counter + 1;

// Poderíamos equivalentemente dizer
counter += 1;

// Ou
counter++;

// Ou para subtrair um
counter--;
```
*Importante:*\
Não precisamos especificar o tipo de counter novamente, pois ele já foi criado.

### Variável constante
- Em vez de comparar uma variável manualmente diversas vezes, podemos criar uma constante,
uma variável que não podemos alterar:
```c
// Também a variável em upper case ajuda a lembrar que ela é uma variável constante
const int MINE = 2;
```

### Bool
Código|Funçao
------|------
**\| \|**| *ou lógico*
**&&**| *e lógico*

*Importante:*
- Em C, o char é colocado entre aspas simples, ' em vez de aspas duplas para strings.
(E strings com apenas um único caractere ainda terão aspas duplas, pois são um tipo
de dados diferente.)

### Loops

- loop **while** em C:
```c
while (true) // Executa o bloco printf para sempre
{
    printf("meow\n");
}
```

- loop **while** com contador:
```c
int i = 0;
while (i < 3)
{
    printf("meow\n");
    i++;
}
```

- loop **for** com contador:
```c
for (int i = 0; i < 3; i++)
{
    printf("meow\n");
}
```

- A lógica na primeira linha é a mesma que acabamos de ver em um loop while.
Primeiro, uma variável i é criada e inicializada 0 com ``int i = 0``.
(Cada uma dessas partes é separada por um ponto e vírgula, apenas por causa de como
a linguagem foi originalmente projetada.)
Então, a condição que é verificada para cada ciclo do loop é ``i < 3.``
Finalmente, após executar o código dentro do loop, a última parte, ``i++``, será executada.

- Uma pequena diferença com um loop for, em comparação com um loop while, é que a variável
criada dentro de um loop for só estará acessível dentro do loop. Por outro lado, a variável
i que criamos fora do loop while ainda estará acessível após o loop while terminar.

### Funções
- Definimos nossa função com ``void meow(void)``.\
A primeira ``void`` significa que não há um valor de retorno para nossa função.\
O `void` dentro dos parênteses também indica que a função não aceita nenhum argumento ou entrada.
- Podemos mover nossa função para o final do arquivo, pois não precisamos saber como ela é
implementada imediatamente.
- O compilador lê nosso código de cima para baixo, então não sabe qual é a função.
Podemos resolver isso declarando nossa função com um protótipo, que apenas informa ao
compilador que definiremos nossa função posteriormente com o tipo de retorno e o tipo
de argumento especificado.
```c
#include <stdio.h>

void meow(void);  // É o protótipo da nossa função

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        meow();
    }
}

void meow(void)  // Função
{
    printf("meow\n");
}
```

- Podemos adicionar um argumento à nossa função `meow`:
```c
#include <stdio.h>

void meow(int n);  // a função recebe uma entrada "int n" que será um numero inteiro

int main(void)
{
    meow(3);
}

void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}
```
