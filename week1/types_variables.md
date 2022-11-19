# Data Types e Variables

## Data Types

### int
- Inteiros até um determinado tamanho ou número de bits
    - Inteiros sempre ocupam 4 bytes de memória (32 bits)
    - Intervalo de valores -2\**31 a 2**31-1 (-1 -> um ponto para 0)
    - Metade dos valores possíveis de em um int são negativos e a outra metade são positivos.\
     São cerca de 2 bilhões negativos e de 2 bilhões positivos

### Qualificadores

#### unsigned int
- Dobra o valor de intervalos positivos anulando os negativos
- 0 a 2\**31 a 2\**32-1 (0 a 2**32-1) ou 0 a aproximadamente 4 bilhões
- Neste caso você efetivamente deixa de usar os valores negativos
- unsigned é um qualificador ao inteiro

#### Outros tipos de dados variáveis
- short
- long
- const

### char
- Usado para um uníco caractere
- Sempre ocupam 1 byte (8 bits)
- Intervalo de valores é de -128 a 0 a 127 (-128 a 127)

### float
- Também conhecidos como números reais
- Ocupam 4 bytes de memória (32 bites)
- Floats tem problema de precisão (por termos apenas 32 bits para usar)

### double
- Assim como o float, double é usado para armazenar números reais (ponto flutuante)
- Tem precisão dupla
- Podem armazenar 8 bytes (64 bits). Podemos ser mais precisos com o ponto decimal

### void
- Não é um tipo de dados
    - Não podemos criar uma variável do tipo **void** e atribuir um valor a ela
- É um tipo
- É chamado de vazio (não retorna um valor)

## Data Types da biblioteca CS50.h

### bool
- Tipo de dados booleano, usado para variáveis
- Contém apenas dois valores **True** e **False**
- Não contém como padrão na linguagem **C**

### string
- São palavras, sentenças e parágrafos
    - Séries de caracteres muito curtas ou muito longas

## Variables

### Criar variáveis
- Para criar uma variável é preciso duas coisas
    - Primeiro atribuir um **tipo**
    - Segundo atribuir um **nome**
- *Lembre de colocar um ponto e vírgula no final da linha*

*Exemplos:*
```c
int number;  // variável numero que contém um inteiro
char letter;  // variável letra que contém um carácter
```
- Para criar várias variávies do mesmo tipo,\
só precisa especificar o nome do tipo uma vez.
```c
int height, width;
float sqrt2, sqrt3, pi;
```

### Uso de variávies
- Uma vez especificado o tipo da variável, não é preciso especifica-la novamente.
- Especificar uma variável mais de uma vez pode ocasionar bugs ao programa.
