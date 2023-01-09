# Data Structures
## Data Structures Summary
### Estrutura de Dados - Resumo

- Neste ponto, examinamos quatro maneiras diferentes de armazenar conjuntos de\
dados:
    - Matrizes (Arrays)
    - Listas encadeadas (Linked lists)
    - Tabelas de hash (Hash tables)
    - Tries
- Existem até algumas variações destes (árvores e montes, bastante semelhante a\
tries, pilhas e filas bastante semelhante a arrays ou listas encadeadas,\
etc.), mas isso geralmente cobrirá a maior parte do que estamos vendo em C.
___

- Como todas essas estruturas de dados se comparam? Como você sabe qual escolher\
para sua situação?
- Normalmente é uma questão de pesar os prós contra os contras. Vamos considerar\
algumas das métricas importantes para cada um.
___

- Matrizes (Arrays)
    - A inserção é ruim - muita mudança para encaixar um elemento no meio
    - A exclusão é ruim - muita mudança após a remoção de um elemento
    - A pesquisa é ótima - acesso aleatório, tempo constante
    - Relativamente fácil de classificar
    - Tamanho relativamente pequeno
    - Preso com um tamanho fixo, sem flexibilidade
___

- listas encadeadas (Linked lists)
    - A inserção é fácil - basta prender na frente
    - A exclusão é fácil - depois de encontrar o elemento
    - A pesquisa é ruim - tem que confiar na pesquisa linear
    - Relativamente difícil de classificar - a menos que você esteja disposto a\
    se comprometer inserção super-rápida e, em vez disso, classifique conforme\
    você constrói
    - Tamanho relativamente pequeno (não tão pequeno quanto os arrays)
___

- Tabelas de hash
    - A inserção é um processo de duas etapas - hash e depois adicionar
    - A exclusão é fácil - depois de encontrar o elemento
    - A pesquisa é, em média, melhor do que com listas vinculadas porque você\
    tem o benefício de um fator constante do mundo real
    - Não é uma estrutura de dados ideal se a classificação for o objetivo -\
    basta usar uma matriz
    - Pode executar toda a gama de tamanhos
___

- Tries
    - A inserção é complexa - muita alocação de memória dinâmica, mas fica mais\
    fácil conforme você avança
    - A exclusão é fácil - apenas libere um nó
    - A pesquisa é rápida – não tão rápida quanto uma matriz, mas quase
    - Já classificado - classifica conforme você constrói em quase todas as\
    situações
    - Torna-se enorme rapidamente, mesmo com muito poucos dados presentes, nada\
    bom se o espaço for escasso
