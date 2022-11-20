# Loops

### Existem três tipos principais de loops

## while loops

### while (true) - loop infinito
- As linhas entre chaves, serão executadas repetidamente de cima para baixo
- A maneira de quebrar este loop, é o uso da instrução **break**
- Caso não tenha a instrução **break**, pode para o programa com *Control-C*
```c
while (true)
{

}
```

### while (boolean-expr)
- O loop sera repetido até que a expressão booleana seja avaliada como falsa.
- Exemplo: você pode ter um contador
```c
while (boolean-expr)
{

}
```

### do while loop
- Este loop executará todas as linhas de código entre as chaves uma vez,\
e em seguida, verificará a expressão booleana
- Se a expressão booleana for verdadeira, ela voltará e repetira o processo\
indefinidamente, até que a expressão booleana seja avaliada como falsa
- Esse loop é garantido para executar pelo menos uma vez
```c
do
{

}
while (boolean-expr)
```

## for loops
- Geralmente utilizado quando você deseja repetir um número específico de vezes.

### loops
```c
for (int i = 0; i < 10; i++)
{

}
```
1. `int i = 0;` Aqui declaramos a variável do tipo inteiro **i**\
e que o valor desta variável será **0**
2. `i < 10;` Aqui é avaliada a expressão booleana, que verifica se i é menor que 10
    - Depois que de executada a linha de código entre chaves, vamos para a terceira parte
3. `i++` Aqui a variável contadora é incrementada, o **i** era zero e agora é um
    - então **i** sera incrementado um a um até se tornar 10 e encerrar o loop

```c
for (start; expr; increment)
{

}
```
- Toda as instruções em **start** são executadas primeiro.\
E também pode haver mais de uma
- Em seguida, a expressão booleana (**expr**) é verificada
    - Se a expressão for verdadeira executa o corpo do loop uma vez
    - Se a expressão for falsa, termina e não executa o corpo do loop
- Depois de executar o corpo do loop uma vez, é feito a parte de **increment**
- Repetimos este processo até que não seja mais verdadeira

## Uso de Loops

### while
- O uso do **while** é feito quando você deseja que um loop repita um número\
desconhecido de vezes, mas possivelmente pode não ser executado.

### do-while
- Quando você deseja que um loop repita um número desconhecido de vezes,\
mas pelo menos uma vez.

### for
- Quando você deseja repetir um loop um número discreto de vezes, embora possa\
não saber o número de vezes no momento em que o programa é compilado.
