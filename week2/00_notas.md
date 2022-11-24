# Semana II

## Compilar Código

*Compliar com o programna make:*

Comando|Função|
-------|------|
**make hello**| *Compilar arquivo hello.c*

*Compliar manualmente:*
Comando|Função
-------|-----|
**clang -o hello hello.c**| *Compilar arquivo hello.c*
*hello (nomeia arquivo compilado)*| *hello.c (compilar o arquivo)*

*Compliar manualmente (incluíndo bibliotecas):*
Comando|Função
-------|-----|
**clang -o hello hello.c -lc50**| *Compilar arquivo hello.c*
obs.: | *-lc50 (informa link da biblioteca a ser inclído no compilador)*
*hello (nomeia arquivo compilado)*| *hello.c (compilar o arquivo)*

*Arquivo hello.c:*
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
}
```

### O processo
- A compilação do código-fonte em código de máquina é, na verdade,
composta de quatro etapas menores:
    - pré-processando
        - Faz a leitura dos **#include <...>**
    - compilando
        - Coverte o código para a **linguagem assembly**
    - montando
        - Tranforma o código assembly para binário
    - ligando (vincular)
        - Combinar os arquivos binários (Ex.: hello.c, cs50.c, stdio.c e ...)

## Memória
- Em C, temos diferentes tipos de variáveis que podemos usar para armazenar dados.\
Cada variável é armazenada com um número fixo de bytes e, para a maioria dos sistemas\
de computador, cada tipo tem o seguinte tamanho:
    - **bool**, 1 byte
        - Um valor booleano pode ser tecnicamente representado com apenas um único bit,\
        mas, para simplificar, nossos computadores usam um byte inteiro.
    - **char**, 1 byte
        - Lembre-se que com ASCII, temos no máximo 256 caracteres diferentes possíveis,\
        pois um byte tem 8 bits.
    - **double**, 8 bytes
        - Duas vezes mais bytes que um arquivo float.
    - **float**, 4 bytes
    - **int**, 4 bytes
        - Lembre-se de que um inteiro de 32 bits pode representar cerca de 4 bilhões\
        de valores diferentes.
    - **long**, 8 bytes
        - Duas vezes mais bytes que um arquivo int.
    - **string**, ? bytes
        - A **string** ocupa uma quantidade variável de espaço, pois pode ser curto ou longo.
- Dentro de nossos computadores, temos chips chamados RAM, memória de acesso **aleatório**,\
que armazena zeros e uns. Podemos pensar nos bytes armazenados na RAM como se estivessem\
em uma grade, um após o outro.

## arrays (matrizes)

*Exemplo:*
```c
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
```

*Mesmo código com melhor design e mais sucinto:*
```c
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
```

## Matrizes
*Exemplo com código:*
```c
// Strings
// Strings são matrizes que terminam com um caractere especial
// '\0', ou um byte com todos os oito bits definidos como 0
// Esse caractere é chamado de caractere nulo ou NUL.
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";

    // %i == int, s[3] == ultimo char/int == \0
    printf("%i %i %i %i\n", s[0], s[1], s[2], s[3]);
}
```

### Manipulando matrizes para obter tamanho de uma string
*Exemplo com código:*
```c
// Verifica tamanho de uma string
#include <cs50.h>
#include <stdio.h>

// biblioteca string de "C"
// Uso da função strlen
#include <string.h>

// Cabeçario da função
int string_length(string s);

int main(void)
{
    string name = get_string("Name: ");

    // funçao da biblioteca string.h
    // int length = strlen(name);

    // Usa a minha função
    int length = string_length(name);

    printf("%i\n", length);
}

// Função que verifica tamnho de uma string
int string_length(string s)
{
    int i = 0;
    // Enquanto caractere for diferente de NUL ('\0')
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}
```

- *Podemos usar as [páginas de manual](https://manual.cs50.io/) do CS50\
para encontrar e aprender sobre bibliotecas e funções.*
- *Veja mais [aqui](https://www.ime.usp.br/~pf/algoritmos/apend/interfaces.html)*

**time lecture: 1h29m24s**:
