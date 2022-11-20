# Operators

## Abreviação de operações
```c
x = x * 5;
// Outra forma
X *= 5;  // Funciona com todos os operadores (+, -, *, /, e %)
```

## Incrementar e decrementar
```c
x = x + 1:
// Outra forma
x++;

x = x - 1:
// Outra forma
x--;
```

## Expressões Booleanas

### True e False com inteiros em "C"
- Em **C**, todo valor diferente de **0** é o mesmo que verdadeiro
- E **0** é falso

### Operadores lógicos

#### **E** lógico (**&&**)
- se x(true) e y(true) --> x && y (true)
- se x(true) e y(false) --> x && y (false)
- se x(false) e y(false) --> x && y (false)
- Ambos tem que ser verdadeiros

#### **OU** lógico (||)
- se x(true) e y(true) --> x || y (true)
- se x(true) e y(false) --> x || y (true)
- se x(false) e y(false) --> x || y (false)
- Um ou ambos tem que ser verdadeiros

#### **Não** lógico (!)
- se x(true), !x(false)
- se x(false), !x(true)
- Inverte o valor, ser for **true** passa a ser **false**, se **false** torna **true**

### Operadores relacionais
- Menor que (x < y)
- Menor ou igual que (x <= y)
- Maior que (x > y)
- Maior ou igual que (x >= y)
- Exemplo: se x < y (retorna true, se não retorna false)

#### Igualdade e diferença
- Igual a (x == y)
- Diferente de (x != y)
