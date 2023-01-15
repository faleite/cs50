# Hash Tables
## Tabelas de hash

- As tabelas hash combinam a capacidade de acesso aleatório de um array com o\
dinamismo de uma lista encadeada.
- Isso significa (supondo que definimos bem nossa tabela hash):
    - A inserção pode começar a tender para 0(1)
    - A exclusão pode começar a tender para 0(1)
    - A pesquisa pode começar a tender para 0(1)
- Estamos obtendo as vantagens de ambos os tipos de estrutura de dados, ao\
mesmo tempo em que mitigamos as desvantagens.
___

- Para obter essa atualização de desempenho, criamos uma nova estrutura em que,\
ao inserir dados na estrutura, os próprios dados nos dão uma pista sobre onde\
encontraremos os dados, caso precisemos procurá-los posteriormente.
- A desvantagem é que as tabelas de hash não são ótimas para ordenar ou\
classificar dados, mas se não nos importamos com isso, estamos prontos!
___

- Uma tabela de hash equivale a uma combinação de duas coisas com as quais\
estamos bastante familiarizados.
    - Primeiro, uma **função hash**, que retorna um valor inteiro não negativo\
    chamado código hash.
    - Em segundo lugar, uma **matriz** capaz de armazenar dados do tipo que\
    desejamos colocar na estrutura de dados.
- A ideia é executarmos nossos dados por meio da função hash e, em seguida,\
armazenarmos os dados no elemento da matriz representado pelo código hash\
retornado.
___
-|Hash Tables|-|Code
-|-|-|-
0| | |// Tabela Hash de strings
1| | |string hashtable[10];
2|
3|
4|
5|
6|
7|
8|
9|
___

-|Hash Tables|-|Code
-|-|-|-
0| | |int x = hash(“John”);
1|
2|
3|
4|
5|
6|
7|
8|
9|
___

-|Hash Tables|-|Code
-|-|-|-
0| | |int x = hash(“John”);
1| | |// x is now 4
2|
3|
4|
5|
6|
7|
8|
9|
___
-|Hash Tables|-|Code
-|:-:|-|-
0| | |int x = hash(“John”);
1| | |// x is now 4
2| | |hashtable[x] = “John”;
3|
4|"john"
5|
6|
7|
8|
9|
___
-|Hash Tables|-|Code
-|:-:|-|-
0| | |int y = hash(“Paul”);
1|
2|
3|
4|"John"
5|
6|
7|
8|
9|
___
-|Hash Tables|-|Code
-|:-:|-|-
0| | |int y = hash(“Paul”);
1| | |// y is now 6
2|
3|
4|"Jonh"
5|
6|
7|
8|
9|
___
-|Hash Tables|-|Code
-|:-:|-|-
0| | |int y = hash(“Paul”);
1| | |// y is now 6
2| | |hashtable[y] = “Paul”;
3|
4|"John"
5|
6|"Paul"
7|
8|
9|
___

- Como definir uma função hash? Realmente não há limite para o número de\
funções de hash possíveis.
- Uma boa função hash deve:
    - Use apenas os dados que estão sendo hash
    - Use todos os dados sendo hash
    - Seja determinista
    - Distribuir dados uniformemente
    - Gerar códigos hash muito diferentes para dados muito semelhantes
```c
unsigned int hash(char* str)
{
int sum = 0;
for (int j = 0; str[j] != ‘\0’; j++)
{
sum += str[j];
}
return sum % HASH_MAX;
}
```
___

- Uma **colisão** ocorre quando dois dados, quando executados pela função hash,\
produzem o mesmo código hash.
- Presumivelmente, queremos armazenar os dois dados na tabela de hash, portanto,\
não devemos simplesmente sobrescrever os dados que conteceu de ser colocado lá\
primeiro.
- Precisamos encontrar uma maneira de obter ambos os elementos na tabela de\
hash enquanto tentamos preservar a inserção e pesquisa rápidas.
___

- Resolução de colisões: sondagem linear
- Neste método, se houver uma colisão, tentamos colocar os dados no próximo\
elemento consecutivo do array (voltando para o início se necessário) até\
encontrar uma vaga.
- Dessa forma, se não encontrarmos o que procuramos no primeiro local, pelo\
menos esperamos que o elemento esteja em algum lugar próximo.
___

- Resolução de colisões: sondagem linear
- A sondagem linear está sujeita a um problema chamado **agrupamento**. Quando\
houver uma falha, duas células adjacentes conterão dados, tornando mais provável\
que o cluster cresça no futuro.
- Mesmo se mudarmos para outra técnica de sondagem, ainda estamos limitado. Só\
podemos armazenar a quantidade de dados que tivermos em nossa matriz.
___

- **Resolução de colisões: encadeamento**
- Vamos começar a juntar tudo.
- E se, em vez de cada elemento do array conter apenas um dado, ele contivesse\
vários dados?
- Se cada elemento da matriz for um ponteiro para o início de uma lista encadeada,\
vários dados podem gerar o mesmo código hash e poderemos armazenar tudo!
- Eliminamos o agrupamento.
- Sabemos por experiência com listas encadeadas que a inserção (e a criação, se\
necessário) em uma lista encadeada é uma operação O(1).
- Para pesquisa, precisamos apenas pesquisar o que esperamos ser uma lista pequena,\
pois estamos distribuindo o que seria uma lista enorme em n listas.
