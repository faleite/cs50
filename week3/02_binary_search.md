# Binary Search

## Perquisa Binária
- É um algoritimo que podemos usar para encontrar um elemento dentro de um uma\
matriz.
- Ao contrário da pesquisa linear, ela exige que uma condição especial seja\
atendida de antemão, e sera muito mais eficiente se essa condição for, de fato\
atendida.
- A ideia é dividir para conquistar:
    - Queremos reduzir pela metade o tamanho da área de pesquisa pela metade\
    a cada vez, para encontrar um número de destino.
    - Para isso a matriz deve estar ordenada, se for uma mistura completa,\
    não podemos descartar a metade dos elemntos, pois não sabemos o que estamos\
    descartando.
    - Mas se matriz estiver ordenada, podemos fazer porque sabemos que tudo à\
    esquerda de onde estamos atualmente deve ser menor do que o valor em que\
    estamos atualmente. E tudo à direita onde estamos deve ser maior do que o\
    valor que estamos vendo no memento.
- Como fazer:
    - Em pseudo-código:
        - Repita, até que a sub(matriz) seja de tamanho 0:
            - Caucule o ponto médio da sub(matriz) atual.
            - Se o valor que esta procurando estiver naquele elemento da\
            sub(matriz), pare.
            - Caso o contrário, se o valor que estamos procurando for menor\
            do que o que vemos, repita esse processo novamamente, mas altere\
            o ponto final, em vez de ser a matriz completa original, para estar\
            à esquerda de onde acabamos de olhar. E assim definiremos a\
            localização da matriz logo à esquerda do ponto médio como o novo\
            ponto final.
            - Por outro lado, se o alvo for maior do que o que está no meio,\
            fazemos exatamente o mesmo processo, mas, em vez disso, alteramos\
            o ponto inicial para ficar logo à direita do ponto médio que\
            acabamos de calcular. E então, começamos o processo novamente.
        - Desta forma nos preocupamos em onde começamos a procurar, onde\
        paramos de procurar, e qual é o ponto médio da matriz atual.

## Complexidade da pesquisa binária
- Na pior dos casos, temos que dividir a matriz
    - Tempo de execução em notação **Big *O***: O(Log n)
- Na melhor das hipóteses, na primeira vez que calculamos o ponto médio\
encontramos o que estamos procurando.
    - Tempo de execução em notação **Big *O***: \Omega(1)
- Portanto, a pesquisa binária é muito melhor do que a pesquisa linear, mas\
você precisa lidar com o processo de ordenar a matriz antes de poder aproveitar\
o poder da *pesquisa binária.*
