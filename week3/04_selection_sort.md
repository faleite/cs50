# Selection Sort
## Ordenar por seleção
- É um algoritimo que ordena um conjunto de elementos
- Na ordenação por seleção, a ideia basica é encontrar o menor elemento não\
não ordenado e adicioná-lo ao final da lista ordenada. Efetivamente, o que isso\
faz é criar uma lista ordenada, um elemento por vez.
- Em pseudo-código isso seria:
    - Repita isso até que nenhum elemento não ordenado permaneça:
        - Pesquise os dados não ordenados para encontrar o menor valor
        - Troque o menor valor pelo primeiro elemento da parte não ordenada

## Complexidade da classificação por seleção
- No pior dos casos, temos que examinar os elementos da matriz para encontrar o\
menor elemento não classificado, e temos que repetir este processo n vezes. Uma\
para cada elemento da matriz, porque neste algoritimo ordenamos apenas um elemento\
por vez.
    - Tempo de exeucção em notação **Big *O***: **O(n2)**
- Na melhor das hipóteses, é exatamento o mesmo, pois percorremos em cada elemento\
da matriz.
    - Tempo de exeucção em notação **Big *O***: **Omega(n2)**
