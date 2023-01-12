# Singly-Linked Lists
## Listas ligadas individualmente

- Até agora no curso, tivemos apenas um tipo de estrutura de dados para\
representar coleções de valores semelhantes.
- structs, lembre-se, nos fornecem “contêineres” para armazenar variáveis de\
diferentes tipos de dados, normalmente.
- Arrays são ótimos para pesquisa de elementos, mas, a menos que desejemos\
inserir no final do array, inserir elementos é bastante caro – lembra-se da\
classificação por inserção?
___

- Os arrays também sofrem de uma grande inflexibilidade – o que acontece se\
precisarmos de um array maior do que pensávamos?
- Por meio do uso inteligente de ponteiros, alocação dinâmica de memória e\
estruturas, podemos juntar essas duas peças para desenvolver um novo tipo de\
estrutura de dados que nos dá a capacidade de aumentar e reduzir uma coleção de\
valores semelhantes para atender às nossas necessidades.
___

- Chamamos essa combinação de elementos, quando usada dessa forma, de **lista\
encadeada**.
- Um **nó** de lista encadeada é um tipo especial de struct com dois membros:
    - Dados de algum tipo de dados (int, char, float…)
    - Um ponteiro para outro nó do mesmo tipo
- Desta forma, um conjunto de nós juntos pode ser pensado como formando uma\
cadeia de elementos que podemos seguir do começo ao fim.
___

```c
typedef struct sllist  // defini a estrutura
{
VALUE val;  // VALUE indica qualquer tipo de dados, como int, float e etc...
struct sllist* next;  // ponteiro para outro nó do mesmo tipo (nome temporário)
}
sllnode;  // (nome permanente)
```
___

- Para trabalhar com listas encadeadas de forma eficaz, há uma série de operações\
que precisamos entender:
1. Crie uma lista encadeada quando ela ainda não existir.
2. Pesquise em uma lista vinculada para localizar um elemento.
3. Insira um novo nó na lista encadeada.
4. Exclua um único elemento de uma lista encadeada.
5. Exclua uma lista encadeada inteira.
___

- Crie uma lista encadeada.
    ```c
    sllnode* create(VALUE val);
    ```

    ```c
    sllnode* new = create(6);
    ```

- Etapas envolvidas:
    - a. Aloque espaço dinamicamente para um novo sllnode.
    - b. Verifique se não ficamos sem memória.
    - c. Inicialize o campo val do nó.
    - d. Inicialize o próximo campo do nó.
    - e. Retorne um ponteiro para o sllnode recém-criado.
___

- Pesquise em uma lista vinculada para encontrar um elemento.
    ```c
    // O primeiro elemento entre parenteses, ...
    // .. é um ponteiro para o primeiro elemento da lista encadeada.
    bool find(sllnode* head, VALUE val);
    ```
    ```c
    bool exists = find(list, 6);
    ```
- Etapas envolvidas:
    - a. Crie um ponteiro de travessia apontando para o topo da lista.
    - b. Se o campo val do nó atual for o que estamos procurando, informe o sucesso.
    - c. Caso contrário, defina o ponteiro de travessia para o próximo ponteiro\
    na lista e volte para a etapa b.
    - d. Se você chegou ao fim da lista, relate a falha.
___

- Insira um novo nó na lista encadeada.
    ```c
    sllnode* insert(sllnode* head, VALUE val);
    ```
- Etapas envolvidas:
    - a. Aloque espaço dinamicamente para um novo sllnode.
    - b. Verifique se não ficamos sem memória.
    - c. Preencha e insira o nó **no início da lista encadeada**.
    - d. Retorne um ponteiro para o novo cabeçalho da lista encadeada.
    ```c
    list = insert(list, 12);
    ```
___

- Hora da decisão!
- Qual ponteiro devemos mover primeiro? O nó “12” deve ser o novo cabeçalho da\
lista encadeada, já que agora existe, ou devemos conectá-lo primeiro à lista?
- Esta é uma das coisas mais complicadas com listas encadeadas. Ordem importa!
    ```c
    list = insert(list, 12);
    ```
___

- Excluir uma lista encadeada inteira.
    ```c
    void destroy(sllnode* head);
    ```
    ```c
    destroy(list);
    ```
- Etapas envolvidas:
    - a. Se você alcançou um ponteiro nulo, pare.
    - b. Exclua **o restante da lista**.
    - c. Libere o nó atual.
___

- Para trabalhar com listas encadeadas de forma eficaz, há uma série de operações\
que precisamos entender:
1. Crie uma lista encadeada quando ela ainda não existir.
2. Pesquise em uma lista vinculada para localizar um elemento.
3. Insira um novo nó na lista encadeada.
4. **Exclua um único elemento de uma lista encadeada.**
5. Exclua uma lista encadeada inteira.
