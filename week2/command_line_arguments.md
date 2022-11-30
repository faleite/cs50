# Command Line Arguments
#### Argumentos de linha de comando

```c
// Dois parametros que são chamados na linha de comando
int main(int argc, string argv[])
{

}
```
- `argc` --> argument count (um número inteiro)
    - Contagem de argumantos passados pela linha de comando
    - O próprio nome do programa conta como um argumento

Command| argc
-------|-----
./greedy| 1
./greedy 1024 cs50| 3

- `argv` --> argumento vetor (é uma matriz (array))
    -  É uma array que armazena strings (uma string por elemento)
    - O primeiro argumento é "0" (argv[0]) e o último é "-1" (argv[argc-1])

*Linha de comando:* **./greedy 1024 cs50**

argv indices| argv contents
-------|-----
argv[0]| "./greedy"
argv[1]| "1024"
argv[2]| "cs50"
