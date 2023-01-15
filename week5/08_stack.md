# Stack (Data Structure)
## Pilhas (Estrutura Dados)

- Uma pilha é um tipo especial de estrutura que pode ser usada para manter os\
dados de forma organizada.
- Essa estrutura de dados geralmente é implementada de duas maneiras: como uma\
**matriz** ou como uma **lista encadeada**.
- Em ambos os casos, a regra importante é que, quando os dados são adicionados\
à pilha, eles ficam “no topo” e, portanto, se um elemento precisar ser\
removido, o elemento adicionado mais recentemente é o único elemento que pode\
ser legalmente removido.
    - Último a entrar, primeiro a sair (LIFO)
___

- Existem apenas duas operações que podem ser executadas legalmente em uma\
pilha.
    - Push: adiciona um novo elemento ao topo da pilha.
    - Pop: remove o elemento adicionado mais recentemente do topo da pilha.
___

- Implementação baseada em array
```c
typedef struct _stack
{
VALUE array[CAPACITY];
int top;
}
stack;
```
```c
stack s;
s.top = 0;  /* Define o topo da lista */
```
___

- Implementação baseada em array
    - **Push**: Adiciona um novo elemento ao topo da pilha.

- No caso geral, push() precisa:
    - Aceite um ponteiro para a pilha.
    - Aceite dados do tipo VALUE para serem adicionados à pilha.
    - Adicione esses dados à pilha no topo da pilha.
    - Alterar a localização do topo da pilha.
___

- Implementação baseada em array
```c
void push(stack* s, VALUE data);
```
```c
stack s;
s.top = 0;  /* Define o topo da lista */
push(&s, 28); /* Coloca o número na localização do array 0 */
```
```c
s.top = 1;  /* Define o topo da lista */
push(&s, 33); /* Coloca o número na localização do array 1 */
```
```c
s.top = 2;  /* Define o topo da lista */
push(&s, 19); /* Coloca o número na localização do array 2 */
```
___

- Implementação baseada em array
    - **Pop**: remove o elemento mais recente do topo da pilha.
- No caso geral, pop() precisa:
    - Aceite um ponteiro para a pilha.
    - Alterar a localização do topo da pilha.
    - Retorne o valor que foi removido da pilha.
___

- Implementação baseada em array
```c
VALUE pop(stack* s);
```
```c
int x = pop(&s);
```
___

- Implementação baseada em lista vinculada
```c
typedef struct _stack
{
VALUE val;
struct _stack *next;
}
stack;
```
___

- Apenas certifique-se de sempre manter um ponteiro para o início da lista\
encadeada!
- Para **empurrar**, aloque dinamicamente um novo nó, defina seu próximo\
ponteiro para apontar para o cabeçalho atual da lista e mova o ponteiro do\
cabeçalho para o nó recém-criado.
___

- Para pop, percorra a lista encadeada até seu segundo elemento (se existir),\
libere o cabeçalho da lista e mova o ponteiro do cabeçalho para o (antigo)\
segundo elemento.
