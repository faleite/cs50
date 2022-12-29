# Hexadecimal

## Sistema Decimal
- A maioria das culturas ocidentais usa o **decimal system**, também conhecido\
como *base-10*, para representar dados numéricos
    - **0 1 2 3 4 5 6 7 8 9**

## Sistema Binário
- Como sabemos, os computadores usam o **binary system**, também conhecido como\
*base-2*, para representar dados numéricos (e de fato todos os dados).
    - **0 1**
- Como cientistas da computação, é útil poder expressar dados da mesma forma\
que o computador faz.
- O problema, é claro, é que tentar analisar uma enorme cadeia de 0s e 1s\
podem ser bastante difíceis.

## Sistema Hexadecimal
- O **hexadecimal system**, também conhecido como *base-16*, é uma maneira\
muito mais concisa de expressar os dados no sistema de um computador.
    - **0 1 2 3 4 5 6 7 8 9 A B C D E F**
- O hexadecimal facilita esse mapeamento porque um grupo de quatro dígitos\
binários (bits) pode ter 16 combinações diferentes, e cada uma dessas\
combinações é mapeada para um único dígito hexadecimal:

Decimal | Binary | Hexadecimal | |Decimal | Binary | Hexadecimal
--------|--------|------------ |-| --------|--------|------------
0 | 0000 | 0 | | 8  | 1000 | 8
1 | 0001 | 1 | | 9  | 1001 | 9
2 | 0010 | 2 | | 10 | 1010 | A
3 | 0011 | 3 | | 11 | 1011 | B
4 | 0100 | 4 | | 12 | 1100 | C
5 | 0101 | 5 | | 13 | 1101 | D
6 | 0110 | 6 | | 14 | 1110 | E
7 | 0111 | 7 | | 15 | 1111 | F

- Para resolver o problema de ambiguidade entre decimal e hexadecimal usamos\
o prefixo **0x**.
- **0x** não siginifica nada na realidade, é apenas uma pista para nós, como\
humanos reconhecer uma notação hexadecimal:

Decimal | Binary | Hexadecimal | |Decimal | Binary | Hexadecimal
--------|--------|------------ |-| --------|--------|------------
0 | 0000 | 0x0 | | 8  | 1000 | 0x8
1 | 0001 | 0x1 | | 9  | 1001 | 0x9
2 | 0010 | 0x2 | | 10 | 1010 | 0xA
3 | 0011 | 0x3 | | 11 | 1011 | 0xB
4 | 0100 | 0x4 | | 12 | 1100 | 0xC
5 | 0101 | 0x5 | | 13 | 1101 | 0xD
6 | 0110 | 0x6 | | 14 | 1110 | 0xE
7 | 0111 | 0x7 | | 15 | 1111 | 0xF

- Assim como o binário tem valores posicionais (1, 2, 4, 8…) e o decimal também\
(1, 10, 100, 1000…), o hexadecimal também.

*Exemplo:*

-| 16^2 | 16^1 | 16^0 | mesmo que: 16 elevado a 2, 16 elevado a 1 e 16
-|------|------|------|-
0x | 3 | 9 | 7 | mesmo que: 256\*3, 16\*9 e 7

-| 16^2 | 16^1 | 16^0
-|------|------|-----
0x | A | D | C

- Para converter um número binário em hexadecimal, agrupe quatro dígitos\
binários (bits) da direita para a esquerda.
    - Preencha o grupo mais à esquerda com 0 bits extras na frente, se\
necessário.
- Em seguida, use o gráfico acima ou sua memória para converter\
esses bits em algo um pouco mais conciso.

*Exemplo:*
Sistema binário|
--------------|
01000110101000101011100100111101

32 bits, organizado em grupos de 4 bits:
4bts|4bts|4bts|4bts|4bts|4bts|4bts|4bts
----|----|----|----|----|----|----|----
0100|0110|1010|0010|1011|1001|0011|1101
4 | 6 | A | 2 | B | 9 | 3 | D

Sistema hexadecimal|
-------------------|
0x46A2B93D
