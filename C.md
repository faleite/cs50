# C

## Notas
___
*Fevereiro 2023*
|Do|Se|Te|Qu|Qu|Se|Sá|obs|
|--|--|--|--|--|--|--|:-:|
|29|30|31|1 | 2| 3| 4| * |
| 5|6 |7 |8 |9 |10|11| * |
|12|13|14|15|16|17|18|   |
|19|20|21|22|23|24|25|   |
|26|27|28|
___

Shell01 |Status
--------|:----:
ex06    | ok

C01  |Status
-----|:----:
ex07 | ok
___

## Artigo

- Função [write( ):](http://codewiki.wikidot.com/c:system-calls:write)
___

- Um **byte** é um espaço com **8 bits**
- int 4 bytes (32 bits)
- Compilador clang, comando gcc que permite olhar ainda mais o código para\
encotrar erros com a flag:
    - gcc -Wall -Werror -Wextra
___

- Contador binário (base 2) 8 bits / 1 bytes:
    - Maior número (2^8) - 1 = 255
    - 255, maior número positivo quando é apenas positivo
    - 127, maior número positivo em 1 bytes
    - -128, menor número negativo em 1 bytes
    - Quando há positivos e negativos o útimo bit representa o sinal negativo (-)

----|128 |64  |32  |16  |8   |4   |2   |1
:--:|----|----|----|----|----|----|----|--
----|2^7 |2^6 |2^5 |2^4 |2^3 |2^2 |2^1 |2^0
12  |0   |0   |0   |0   |1   |1   |0   |0
255 |1   |1   |1   |1   |1   |1   |1   |1
-1  |1   |1   |1   |1   |1   |1   |1   |1
127 |0   |1   |1   |1   |1   |1   |1   |1
-128|1   |0   |0   |0   |0   |0   |0   |0
___

### Variáveis
- char (tamanho 1 byte (8 bites))
```c
#include <stdio.h>

int main()
{
    char c;

    // "%lu" inteiro decimal unsigned long
    printf("%lu\n", sizeof(c));
}
// Saída
// 1
```
- Compilar e executar arquivo:
```sh
gcc char.c && ./a.out
```

- Ler e escrever inteiros
Para ler ou escrever inteiros short, long ou unsigned devemos usar formatos específicos em\
scanf e printf.
    - Casos mais comuns:
        - **"%u"**
        inteiro decimal unsigned
        - **"%ld"**
        inteiro decimal long
        - **"%lu"**
        inteiro decimal unsigned long

- Tabela ascii no terminal:
    - ``$ man ascii``
    - veja em "The decimal set"

```c
#include <stdio.h>

int main()
{
    char c;

    // "k" na tabela decimal ascii equivale a "107"
    c = 'k';

    // "%lu" inteiro decimal unsigned long
    // "%d" imprime inteiro
    // "%c" imprime caractere
    printf("%lu %d %c\n", sizeof(c), c, c);
}
// saida: 1 107 k
```
___

- Tabelas estáticas
```c
#include <stdio.h>

int main()
{
    // ao invés de declaramos varias variáveis podemos usar uma tabela
    // aqui temos uma tabela de números inteiros de "0 a 9"
    int a[10];

    // para acessarmos as variáveis usamos os indices
    a[0] = 12;
    a[1] = 1234;
    a[9] = 15;
    a[3] = a[0];

    printf("%d\n", a[3]);
}
// Saída: 12
```
- Pdemos fazer tabelas de várias dimenssões
     - tabela de duas dimenssões:
```c
#include <stdio.h>

int main()
{
    // tabela com duas dimenssões, onde tenho 10 vezes 10 ints na memória contígua.
    // onde nos empresta 100 ints
    int a[10][10];
    int b;

    b = 3;
    // para acessarmos as variáveis usamos os indices
    // é possivel usar variáveis entre colchetes
    a[0][b] = 12;
    a[1][0] = 1234;
    a[9][7] = 15;
    a[3][6] = a[0][b];
    a[0][a[9][7]] = 12;

    printf("%d\n", a[3][6]);
}
// Saída: 12
```
___

- *Não se pode utilizar a mesma variavel mais de uma vez na mesma linha*
___

### Operadores Binários

*Exemplo base:*
```c
a = 11, b = 6
a = 00001011 (valor binário: 8-bit)
b = 00000110 (8-bit)
``````
*Os três principais são: **&**, **|** e **^**.*

1. Operador **&** (*and*)
    - Olha os bits um por um e os compara.
    - Se **os dois** bits estão em 1, então o bit final será 1.
    - caso contrário o bit final será 0.
```c
00001011
00000110
&
00000010
```

2. Operador **|** (*or*)
    - Olha os bits um por um e os compara.
    - Se **ao menos** um dos dois bits estão em 1, então o bit final será 1.
    - caso contrário o bit final será 0.
```c
00001011
00000110
&
00001111
```

3. Operador **^** (*xor*)
    - Olha os bits um por um e os compara.
    - Se **apenas** um dos dois bits estiver em 1, então o bit final será 1.
    - caso contrário o bit final será 0.
```c
00001011
00000110
&
00001101
```
___

4. Operador **~** (*complemento*)
    - *Operador **unário** que atua diretamente **em uma** variável binária.*
    - Ele inverte o conjunto de bits.
    - Se o bit for 0, ele retorna 1.
    - Se o bit for 1, ele retorna 0.
    - É o operador de negação, permite inverter o conjunto de valores.

```c
00001011
~
11110100
```

5. Operador de descolacamento de bits **<<** (*Left Shift*)
    - *Operador **unário** que atua diretamente **em uma** variável binária.*
    - Ele desloca os bits para a esquerda.

```c
00001011
<<
00010110
```

```c
00001011
<< 2  // Deslocamento de 2 bits a esquerda
00101100
```

```c
00001011
<< 8  // Deslocamento de 8 bits a esquerda
00000000
```

6. Operador de descolacamento de bits **>>** (*Right Shift*)
    - *Operador **unário** que atua diretamente **em uma** variável binária.*
    - Ele desloca os bits para a direita.

```c
00001011
>> 1  // Deslocamento de 1 bit a direita
00000101
```

```c
00001011
>> 3  // Deslocamento de 3 bits a direita
00000001
```

```c
00001011
>> 4  // Deslocamento de 4 bits a direita
00000000
```

*Exemplo particular:*
```c
10000000  // Valor negativo: -128
>> 1  // Deslocamento de 1 bit a direita
11000000  // Quando o valor binário for negativo, sera usado o mesmo valor anterior
// neste caso desloca usando o 1 por ser o 1 que estava na extrema equerda.
```

>*Desaconselhavel trablahar com operadores binários no float, se não souber\
exatamente o que esteja fazendo, pois no float 1 e 0 não valem exatamente o\
mesmo que no int*
___

### Condicional switch
- O **switch** é o que nos permite substituir uma cadeia de **if**, **elseif** e **else**.
- É uma série com várias condições com o objetivo de executar instruções.
- Trabalha com apenas uma variável, e um parâmetro.
- No lugar do if, elseif usa-se **case**
- No lugar do else usa-se **default**
- Se uma condição **case** for verdadeira, retorna todos os outros cases subsequêntes
- Para mudar este comportamento utilizamos o **break**

*Código exemplo:*
```c
#include <stdio.h>

int	main(void)
{
    int a;
    a = 42;

    // Switch
    switch (a)
    {
        case 41:  // se 'a' for igual a 41, faça:
            printf("Hello\n");
            break; // se este case for verdadeiro, faça e saia do programa
        case 42:
            printf("Word\n");
            // se este case for verdadeiro, faça e execute todos os cases subsequentes
        case 43:
            printf("This is\n");
            break;
        default:  // não importa a ordem do default, se comportara da mesma forma
            printf("Awesome\n");
    }


    // Usando o if, elseif e else
    if (a == 41)
        printf("Hello\n");
    else if (a == 42)
        printf("Word\n");
    else if (a == 43)
        printf("This is\n");
    else
        printf("Awesome\n");
}
```
___

### Condicional Ternario

- Permite fazer o uso do if e else, em apenas uma linha
- O operador espera uma condição com uma interrogação no final
    - Ex.: **a == 42 ?**
- Se true, retorna a opção apos a interrogação
    - Ex.: a == 42 ? **12**
- Se false retorna o else, que é a opção após dois pontos
    - Ex.: a == 42 ? 12 : **13**
- O ternário não é um condicional puro, mas sim um operador. Ou seja,\
ele dara um valor de retorno. Retorna o valor desta forma:
    - Ex.: **b =** a == 42 ? 12 : 13 ;
```c
#include <stdio.h>

int	main(void)
{
    int a;
    int b;

    a = 42;

    // Uso do operador ternário
    b = a == 42 ? 12 : 13 ;

    // Mesmo com if else
    if (a == 42)
        b = 12;
    else
        b = 13;

    printf("%d\n", b);
}
```
- Operador ternário me permite retornar uma variável:
```c
int	main(void)
{
    int a;

    a = 41;

    // Operador ternário me permite retornar uma variável:
    printf("%d\n", a == 42 ? 12 : 13);
}
```
___

### While

- O limite do while é refeito na medida em que a condição é != 0.
    - Enquanto o que esta entre parênteses for !=0
    - Efetue o que esta nas chaves abaixo

*Exemplo com código:*

```c
#include <stdio.h>

int main(void)
{
    int tab[10];
    int i;

    /* Atribui valores em cada index na array tab[10] */
    i = 0;
    while (i < 10)
    {
        // atribui sequência de 0 a 9
        tab[i] = i;

        // atribui sequência exponecial i * i
        tab[i] = i * i;

        i++;
    }

    /* Imprime os valores de cada index da array tab[0] */
    i = 0;
    while (i < 10)
    {
        printf("%d\n", tab[i]);
        i++;
    }
}
```
*Mesmo esquema com o loob **for**:*

```c
#include <stdio.h>

int main()
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", i);
    }
}
```
___

### do while

- É quase a mesma coisa que o laço **while**, porém iremos regressar pelo menos\
uma vez no escopo
- Com o **do while** executamos pelo menos uma vez o que temos no escopo, e\
depois faremos a condição while.
```c
#include <stdio.h>

int main()
{
    int i;

    i = 10;
    /* Com "do" passa uma vez no escopo
     * imprime a variavel e vai para o loop while */
    do
    {
        printf("%d\n", i);
        i++; // i passa a valer 11
    }
    while (i < 10); // checa a condição antes de ir para o escopo
}
```
___

### break e continue

- **break** e **continue**, são duas palavras-chave de controle de loop.
- Já vimos **break** com o **switch**: *me deixa sair do switch assim que o encontro*.
```c
#include <stdio.h>

int main()
{
    int i;
    int j;

    i = 0;
    while (i < 10)
    {
        j = 0;
        while (j < 10)
        {
            printf("%d %d\n", i, j);
            /* Para o laço j, imprime j sempre com seu valor inicial
             * Imprimi i interando no laço i */
            break;
            j++;
        }
        i++;
    }
    printf("I am out\n");
}

```
- **continue** possibilita voltar até a condicional, reiniciar outro loop imediatamente.
- Ele vai levar ao topo do loop, e reiniciar o próximo loop.

```c
#include <stdio.h>

int main()
{
    int i;

    for (i = 0; i < 10; i++)
    {
        printf("%d\n", i);
        /* no laço for, ele retornara ao topo do laço
         * imprimindo e incrementando a variavel i
         * e não executara nada no escopo que estiver
         * além do "continue"  */
        continue;
        printf("NEVER EVER\n");
    }
    printf("I am out\n");
}
```

```c
#include <stdio.h>

int main()
{
    int i;

    i = 0;
    while (i < 10)
    {
        printf("%d\n", i);
        /* no laço while, ele retornara ao topo do laço
         * infinitamente imprimindo 0 da variavel i
         * e não executara */
        continue;
        i++;
    }
    printf("I am out\n");
}
```
___

### labels e goto

- O **goto** é o ancestral do *loop while* e deve ser usado com parcimônia,\
ele é superperigoso como ferramenta.

*Exemplo com código:*
```c
#include <stdio.h>

int main()
{
    int i;

    i = 0;
bla: // label
    printf("%d\n", i);
    i = 0;
    while (i < 10)
    {
        printf("%d\n", i);
        i++;
        goto bla;  // va para o label "bla" e continue a partir do bla
    }
    printf("I am out\n");
}
```
___

### Funções

- Criar uma função:
    - 1. Declarar o *tipo de valor de retorno*
    - 2. Nomear a função + fecha e abre parênteses
    - 3. Declarar os argumentos da função
```c
/* "void" é um tipo de valor de retorno que significa "nada"
* fct é o nome da função
* void argumento da função
* {} escopo da função*/
void fct(void)
{
    printf("Hello\n");
}
```
- Protótipo
    - Serve para fazer o programa entender que nossa função existe
    - Um programa **C** se lê de maneira linear
    - Um protótipo permite definir a função no início do programa
    - Desta forma a função principal (main) pode permanecer acima da funções\
    que seram criadas.
```c
/* Protótipo da função */
void fct(void);
```

- **return**
    - Valor de retorno de uma função
    - Palavra chave **return**, nos permite retornar um valor em um retorno\
    de função.

- **Argumentos de função**
    - São valores de entrada que poderemos usar no interior da função
___

### Recursão
*Exemplo com código:*
```c
#include <stdio.h>

int mult(int a, int b)
{
    return (a * b);
}


int mult_loop(int a, int b)
{
    int ret;

    ret = 0;
    while (b != 0)
    {
        if (b < 0)
        {
            ret -= a;
            b++;
        }
        else
        {
            ret += a;
            b--;
        }
    }
    return (ret);
}

/* Recursão */
int mult_rec(int a, int b)
{
    if (b == 0)
        return 0;
    if (b < 0)
        return -a + mult_rec(a, b + 1);
    return a + mult_rec(a, b - 1);
}

int main(void)
{
    printf("Multiplicação com operador *\n");
    printf("%d\n", mult(4, 3));
    printf("\n");

    printf("Multiplicação com loop\n");
    printf("%d\n", mult_loop(4, 3));
    printf("\n");

    printf("Multiplicação com recursão\n");
    printf("%d\n", mult_rec(4, 3));

    return (0);
}

```
___

### Ponteiros

- O **ponteiro** é um tipo de váriavel, que possibilita a criação de memória.
- A memória é dividida em duas partes:
    - **Stack** que é o topo da memória, armazenada de forma decrescentem do\
    maior pro menor.
    - **Heap** é a parte de baixo dos endereços, armazena de forma crescente\
    do menor pro maior.
- A memória é virtutal, e antes será mapeda em algo físico, como nas tiras\
da **RAM**, e seu **Hard Drive**.
- Os **ponteiros** serão a ferramenta que permite recuperar o endereço de uma\
variável para poder acessá-la e utilizá-la.
___

- Declaração e atribuição de um ponteiro.
    1. Declarar uma variável, é preciso saber o tipo da variável.
    2. Declarar um ponteiro (*), arterisco é o simbolo do ponteiro.
    3. Seguido do nome do ponteiro, ex.: *ptr

*Exemplo com código:*
```c
#include <stdio.h>

int main(void)
{
    int a;

    // Declação do ponteiro
    int *ptr;
    // Declaração de ponteiro de um ponteiro
    int **ptr2;

    // Recuperar o endereço de "int a;"
    ptr = &a;  // &a leva ao endereço de "int a;"
    printf("%p\n", ptr);
    // Recuperar o endereço de um ponteiro
    ptr2 = &ptr;
    printf("%p\n", ptr2);

    return (0);
}
```
___

### Desreferenciação de um ponteiro

- Desreferenciação de um ponteiro, é quando um ponteiro tem o endereço de uma\
variável, e vemos o que há nesse endereço. E poder modificar a variável que o\
ocupa. *Esse é o uso de ponteiros.*

*Exemplos:*

```c
#include <stdio.h>

int main(void)
{
    int     a;
    int     *ptr;

    a = 56;
    ptr = &a;
    /*  ptr no momento, é o endereço de a.
    *   *ptr no momento, exibe o valor que esta em seu endereço  */
    printf("%d\n", *ptr);
    /*  Modificar "int a" usando a desreferenciação
     *  Atribui a variavel "int a" o valor atribuido ao "*ptr" */
    *ptr = 78;
    printf("%d\n", a);
    return (0);
}
```

```c
#include <stdio.h>

int main(void)
{
    int     a;
    int     *ptr;
    int     **ptr2;
    int     ***ptr3;
    int     ****ptr4;
    int     *****ptr5;
    int     ******ptr6;

    a = 42;
    ptr = &a;
    ptr2 = &ptr;
    ptr3 = &ptr2;
    ptr4 = &ptr3;
    ptr5 = &ptr4;
    ptr6 = &ptr5;

    printf("%d\n", ******ptr6);  // Saida: 42
    return (0);
}
```
Step --> **C - VI - 5**
