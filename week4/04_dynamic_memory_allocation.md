# Dynamic Memory Allocation
## Alocação Dinâmica de Memória
- Vimos uma maneira de trabalhar com ponteiros, ou seja, apontar uma variável\
de ponteiro para outra variável que já existe em nosso sistema.
    - Isso exige que saibamos exatamente quanta memória nosso sistema\
    precisará no momento em que nosso programa for compilado.
- E se **não** soubermos quanta memória precisaremos em tempo de compilação?\
Como obtemos acesso à nova memória enquanto nosso programa está em execução?
___

- Podemos usar ponteiros para obter acesso a um bloco de **memória alocada\
dinamicamente** em tempo de execução.
- A memória alocada dinamicamente vem de um pool de memória conhecido como\
**heap*** (amontoar).
- Antes deste ponto, toda a memória com a qual trabalhamos vinha de um pool de\
memória conhecido como **pilha** (stack).
___

- Obtemos essa memória alocada dinamicamente fazendo uma chamada à função da\
biblioteca padrão C malloc(), passando como parâmetro o número de bytes\
solicitados.
- Depois de obter memória para você (se puder), malloc() retornará um ponteiro\
para essa memória.
- E se malloc() **não puder** fornecer memória? Ele vai te devolver NULL.

```c
// statically obtain an integer
int x;  // cria variável chamada "x" em stack
// dynamically obtain an integer
int *px = malloc(4);  // reserva um espaço dinamicamente na memória em heap
// Other way
int *px = malloc(sizeof(int));
```
```c
// get an integer from the user
int x = GetInt();
// array of floats on the stack
float stack_array[x];
// array of floats on the heap
float* heap_array = malloc(x * sizeof(float));
```
___

- Aqui está o problema: a memória alocada dinamicamente não é devolvida\
automaticamente ao sistema para uso posterior quando a função na qual foi\
criada termina a execução.
- Deixar de devolver a memória ao sistema quando terminar resulta em um\
**vazamento de memória** que pode comprometer o desempenho do sistema.
- Ao terminar de trabalhar com a memória alocada dinamicamente, você deve\
liberá-lo, free().
```c
char* word = malloc(50 * sizeof(char));

// do stuff with word

// now we’re done working with that block
free(word);
```
___

### Três regras de ouro:

1. Cada bloco de memória que você reserva em **malloc()** deve ser\
subseqüentemente liberado com **free()**.
2. Somente a memória que você reserva em **malloc()** deve ser  liberada com\
**free()**.
3. Não libere um bloco de memória mais de uma vez.
