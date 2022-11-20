# Conditional Statements
(Declarações condicionais ou Ramificação condicional)

## Condicionais
- Se a expressão booleana na instrução **if** for verdadeira, todas as linhas de código\
entre as chaves serão executadas em ordem de cima para baixo.
- Se a expressão for falsa, pularemos tudo entre as chaves.
```c
if (boolean-expression)
{
    // linha de código entre chaves
}
```

- Podemos adicionar a intrução **else**
- Se a expressão bool do **if** for falsa isso acionará o **else**
```c
if (boolean-expression)
{
    // linha de código entre chaves
}
else
{
    // linha de código entre chaves
}
```

- Também podemos adicionar **if-else**
- É uma cadeia de if-else if-else...else
```c
if (boolean-expr1)  // se for verdade, execute as linha entre chaves
{
    // fisrt branch
}
else if (boolean-expr2)  // Caso contrário, se isso for verdade, execute...
{
    // second branch
}
else if (boolean-expr3)  // Caso contrário, se isso for verdade, execute...
{
    // third branch
}
else  // Caso contrário, execute as linhas entre chaves
{
    // fourth branch
}
```

- É possível criar ramificações não mutuamente exclusivas.
- Neste exemplo apenas a terceira e a quarta ramificação são mutuamente exclusivas
```c
if (boolean-expr1)  // se for verdade, execute as linha entre chaves
{
    // fisrt branch
}
if (boolean-expr2)  // se for verdade, execute as linha entre chaves
{
    // second branch
}
if (boolean-expr3)  // se for verdade, execute as linha entre chaves
{
    // trird branch
}
else  // Caso contrário, execute as linhas entre chaves
{
    // fourth branch
}
```

## switch()
- switch (trocar, mudar, interroptor...), é uma instrução condicional que permite\
especificar casos distintos, em vez de depender de expressões booleanas\
para tomar decisões por você.
- é importante quebrar; entre cada caso, ou você "cairá"
```c
int x = GetInt();  // "x" recebe um número inteiro do usuário em "GetInt()"
switch(x)  // Depedendo do que o usuário digita eu imprimo na tela
{
    case 1:  // Se o usuário digita 1
        printf("One!\n");  // Eu imprimo "One!"
        break;  // Então eu paro (quebro)
    case 2:  // Se o usuário digita 2
        printf("Two!\n");  // Eu imprimo "Two!"
        break;  // Então eu paro (quebro)
    case 3:  // Se o usuário digita 3
        printf("Three!\n");  // Eu imprimo "Three!"
        break;  // Então eu paro (quebro)
    default:  // Valor default
        printf("Sorry!\n");  // Eu imprimo "Sorry!"
}
```
- Exemplo de código com omissão do break
- Neste código faz um contador de lançamento de foguete
- Pode ser ultil em alguns casos...
```c
int x = GetInt();  // "x" recebe um número inteiro do usuário em "GetInt()"
switch(x)  // Depedendo do que o usuário digita eu imprimo na tela
{
    case 5:  // Se o usuário digita 5, eu imprimo 5, 4, 3, 2, 1, Blast-off!
        printf("Five, ");
    case 4:  // Se o usuário digita 4, eu imprimo 4, 3, 2, 1, Blast-off!
        printf("Four, ");
    case 3:  // Se o usuário digita 3, eu imprimo 3, 2, 1, Blast-off!
        printf("Three, ");
    case 2:
        printf("Two, ");
    case 1:
        printf("One, ");
    default:
        printf("Blast-
                off!\n");
}
```

## Operador ternário "?:"
- Permite que você simule um **if else** com ramificações condicionais pequenas
- Você não usaria **?:** se por exemplo tivesse seis linhas de código\
entre cada conjunto de chaves

*Código comum:*
```c
int x;
if (expr)
{
    x = 5;
}
else
{
    x = 6;
}
```
*Mesmo código com o operador ternário:*
```c
// "?" pergunta se a expressão é verdadeira
int x = (expr) ? 5 : 6;  // Se sim "x = 5", se não "x = 6"
```

## Resumo

### if
- (e if-else, e if-else, e if-...-else)
- Usa expressões booleanas para tomar decisões

### switch
- Usa casos distintos para tomar decisões

### ?:
- Usado para substituir formas simples do if-else
