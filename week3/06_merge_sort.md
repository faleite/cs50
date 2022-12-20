# Merge Sort
## Classificação de mesclagem
- A idéia é classificar matrizes menores e depois combiná-los ou mesclá-los, em\
ordem de classificação.
- Em vez de pensar que temos uma uma matriz de seis elementos, pensamos que temos\
seis matrizes de um elemento, e então vamos apenas recombiná-los na ordem correta\
e mesclá-los.
- merge sort, também faz uso de recursão
- Em pseudo-código:
    - Ordene a metade esquerda da matriz
    - Ordene a metade direita da matriz
    - Mescle as duas metades

## Complexidade da classificação por seleção
- No pior cenário, temos que dividir n elementos. E então temos que recombiná-los,\
dobrando efetivamente os arrays classificados à medida que os construímos. Então,\
pegamos duas matrizes de um elemento e as transformamos em uma matriz de dois\
elementos. Tomamos duas matrizes de dois elementos, e transformamos em uma matriz\
de quatro elementos. E assim por diante... enquanto avançamos.
    - Tempo de exeucção em notação Big O: O(n log n)
- Na melhor das hipóteses, como a classificação por seleção, a matriz já está\
classificada, mas não sabemos disso.
    - Tempo de exeucção em notação Big O: Omega(n log n)

