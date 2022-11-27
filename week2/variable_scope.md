# Variable Scope

- **Scope** é uma característica de uma variável que define a partir de quais\
funções essa variável pode ser acessada.
- Existem dois escopos principais em "C", `varáveis locais` e `variáveis globais`
    - **Variáveis locais** só podem ser acessadas dentro das funções\
    em que são criadas. Elas não podem ser acessados por qualquer outra\
    função existente em seu programa.
    - **Variáveis globais**, por outro lado, podem ser acessadas por quelquer\
    funçao do programa. Elas não são criadas dentro uma função específica.\
    Elas são declaradas fora de todas as funções.

*Exemplo - Variável local:*
```c
int main (void)
{
    // "int result" é uma variável local de "main()"
    // nem uma outra funçao além de main(), consegue acessa-la
    int result = triple(5);
}

// "int x" é uma variável local de "triple()"
// nem uma outra funçao além de triple(), consegue acessa-la
int triple(int x)
{
    return x * 3;
}
```

*Exemplo - Variável global:*
```c
#include <stdio>

// Variável global, todos podem acessa-la
float global = 0.5050;

int main (void)
{
    triple();
    // "global" é uma variável global
    printf("%f\n", global);
}

void triple(void)
{
    // "global" é uma variável global
    global *= 3;
}
```
