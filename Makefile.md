# Makefile

- Makefile é um arquivo específico que permite organizar a compilação com\
algumas regras.

### Compliar na linha de comando
```c
/* Faz compilação unindo dois arquivos:
 * função main.c e a função fct.c
 * E da o nome da compilação de "hello" */
$ cc -o hello main.c fct.c

// Executando a compilação
$ ./hello
```
___

### Usando o Makefile
- Regras simples de compilação:
    - crie um arquivo Makefile desta forma:
```c

all:
        cc -o hello main.c fct.c
```
- usar o Makefile:
```c
// isso abre o Makefile encontra a primeira regra e a executa na sequência
$ make

// saida:
cc -o hello main.c fct.c
```
