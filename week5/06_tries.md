# Tries

- Vimos algumas estruturas de dados que lidam com o mapeamento de pares\
chave-valor.
    - Arrays: A chave é o índice do elemento, o valor são os dados naquele\
    local.
    - Tabelas de hash: a chave é o código de hash dos dados, o valor é uma\
    lista vinculada de hash de dados para esse código de hash.
- Que tal um tipo ligeiramente diferente de estrutura de dados em que a chave é\
única e o valor pode ser tão simples quanto um booleano que informa se os dados\
existem na estrutura?
___

- Tries combina estruturas e ponteiros para armazenar dados de uma maneira\
interessante.
- Os dados a serem pesquisados no trie agora são um roteiro.
    - Se você pode seguir o mapa do começo ao fim, os dados existem no trie.
    - Se não puder, não.
- Ao contrário de uma tabela de hash, não há colisões e não há duas partes de\
dados (a menos que sejam idênticas) com o mesmo caminho.
___

- Vamos mapear pares chave-valor onde as chaves são anos de quatro dígitos\
(YYYY) e os valores são nomes de universidades fundadas durante esses anos.
- Em uma trie, os caminhos de um nó raiz central para um nó folha (onde\
estariamos nomes das escolas) seriam rotulados com os dígitos do ano.
- Cada nó no caminho da raiz à folha pode ter 10 ponteiros emanados dele, um\
para cada dígito.
- Para inserir um elemento na trie, basta construir o caminho correto da raiz\
até a folha.
```c
typedef struct _trie
{
char university[20];
struct _trie* paths[10]; // Raiz de ponteiros
}
trie;
```
___

- Para procurar um elemento no trie, use dígitos sucessivos para navegar a\
partir da raiz e, se conseguir chegar ao fim sem chegar a um beco sem saída\
(um ponteiro NULL), você o encontrou.
