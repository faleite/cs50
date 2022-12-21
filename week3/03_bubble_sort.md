# Bubble Sort
- **Bubble Sort** é um algoritimo que pode ser usado para classificar um conjunto\
de elementos.
- Geralmente queremos ordernar elementos de valor mais baixo para a esquerda e\
o de valor mais alto para a direita.
- Como podemos fazer isso em pseudocode:
    - Defina um contador de troca para um valor diferente de zero.
    - Repita o seguinte processo até que o contador de trocas seja 0:
        - Redefina o contador de troca para 0 se já não for 0
        - Observe cada par de elementos adjacentes.
            - Se esses dois elementos não estiverem em ordem, troque-os\
            e adicione 1 ao contador de troca.

## Complexidade do Bubble Sort
- Na pior dos casos, a matriz está em ordem completamente inversa, e portanto\
temos que iterar por cada um dos elementos grandes por toda matriz. E também\
temos que colocar todos os pequenos elementos de volta em toda a matriz.
    - Tempo de execução em notação Big O: O(n2)
- Na melhor das hipóteses, a matriz ja esta ordenada quando encontramos o que\
estamos procurando. Não precisamos fazer nenhuma troca na primeira passagem.
    - Tempo de execução em notação Big O: Omega(n)
