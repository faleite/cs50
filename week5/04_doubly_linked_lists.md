# Doubly-Linked Lists
## Listas Duplamente Ligadas

- As listas com links simples realmente ampliam nossa capacidade de coletar e\
organizar dados, mas sofrem de uma limitação crucial.
    - Só podemos nos mover em uma direção na lista.
- Considere a implicação que teria ao tentar excluir um nó.
- Uma lista duplamente encadeada, por outro lado, nos permite mover para frente\
e para trás na lista, simplesmente adicionando um ponteiro extra à nossa\
definição de struct.
```c
typedef struct dllist
{
VALUE val;
struct dllist* prev;
struct dllist* next;
}
dllnode;
```
___

- Para trabalhar com listas encadeadas de forma eficaz, há uma série de\
operações que precisamos entender:

1. *Crie uma lista encadeada quando ela ainda não existir*.
2. *Pesquise em uma lista vinculada para localizar um elemento*.
3. **Insira um novo nó na lista encadeada**.
4. **Exclua um único elemento de uma lista encadeada**.
5. *Exclua uma lista encadeada inteira*.
___

- Insira um novo nó na lista encadeada.
```c
dllnode* insert(dllnode* head, VALUE val);
```

- Etapas envolvidas:
    - a. Alocar espaço dinamicamente para um novo dllnode.
    - b. Verifique se não ficamos sem memória.
    - c. Preencha e insira o nó no início da lista encadeada.
    - d. **Fixe o ponteiro anterior do cabeçalho antigo da lista encadeada**.
    - e. Retorne um ponteiro para o novo cabeçalho da lista encadeada.
    ```c
    list = insert(list, 12);
    ```
- Lembre-se, nunca podemos quebrar a corrente ao reorganizar os ponteiros.
- Mesmo que precisemos ter ponteiros redundantes temporariamente, tudo bem.
___

- Excluir um nó de uma lista encadeada.
```c
void delete(dllnode* target);
```
- Etapas envolvidas:
    - a. Fixe os ponteiros dos nós circundantes para “pular” o alvo.
    - b. alvo livre.
___

- As listas encadeadas, de variedades de encadeamento simples e duplo, suportam\
inserção e exclusão de elementos extremamente eficientes.
    - Na verdade, essas operações podem ser feitas em **tempo constante**.
- Qual é a desvantagem? Lembra como tivemos que encontrar um elemento?\
Perdemos a capacidade de acessar aleatoriamente os elementos da lista.
    - Acessar um elemento desejado agora pode levar **tempo linear**.
