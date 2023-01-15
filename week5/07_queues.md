# Queues
## Filas

- Uma fila é um tipo especial de estrutura que pode ser usada para manter os\
dados de forma organizada.
- Essa estrutura de dados geralmente é implementada de duas maneiras: como uma\
**matriz** ou como uma **lista encadeada**.
- Em ambos os casos, a regra importante é que, quando os dados são adicionados\
à fila, eles são colocados no final e, portanto, se um elemento precisar ser\
removido, o elemento na frente é o único que pode ser legalmente removido.
- Primeiro a entrar, primeiro a sair (FIFO)
___

- Existem apenas duas operações que podem ser executadas legalmente em uma fila.
- **Enqueue**: Adiciona um novo elemento ao final da fila.
- **Dequeue**: Remove o elemento mais antigo da frente da fila.
___

- Implementação baseada em array
```c
typedef struct _queue
{
VALUE array[CAPACITY];
int front;
int size;
}
queue;
```

- Implementação baseada em array
```c
queue q;
q.front = 0;
q.size = 0;
```
___

- Implementação baseada em array
- **Enqueue**: Adiciona um novo elemento ao final da fila.

- No caso geral, enqueue() precisa:
    - Aceite um ponteiro para a fila.
    - Aceitar dados do tipo VALUE para serem adicionados à fila.
    - Adicione esses dados à fila no final da fila.
    - Alterar o tamanho da fila.
___

- Implementação baseada em array
```c
void enqueue(queue* q, VALUE data);
```
```c
enqueue(&q, 28);
```
```c
enqueue(&q, 33);
```
```c
enqueue(&q, 19);
```
___

- Implementação baseada em array
    - **Dequeue**: Remove o elemento mais recente da frente da fila.

- No caso geral, dequeue() precisa:
    - Aceite um ponteiro para a fila.
    - Alterar a localização do início da fila.
    - Diminua o tamanho da fila.
    - Retorne o valor que foi removido da fila.
___

- Implementação baseada em array
```c
VALUE dequeue(queue* q);
```
```c
int x = dequeue(&q);
```
___

- Implementação baseada em array
```c
typedef struct _queue
{
VALUE val;
struct _queue *prev;
struct _queue *next;
}
queue;
```
___

- Apenas certifique-se de sempre manter os ponteiros para o início e fim da\
lista encadeada! (provavelmente global)

- Para **enfileirar**:
- Alocar dinamicamente um novo nó;
- Definir seu próximo ponteiro para NULL, definir seu ponteiro anterior para a\
cauda;
- Definir o próximo ponteiro da cauda para o novo nó;
- Mova o ponteiro da cauda para o nó recém-criado.
___

- Para **desenfileirar**:
    - Percorrer a lista encadeada até seu segundo elemento (se existir);
    - Liberar o cabeça de lista;
    - Mova o ponteiro da cabeça para o (antigo) segundo elemento;
    - Faça o ponteiro anterior desse nó apontar para NULL
