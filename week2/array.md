# Arrays (Matrizes)

- Arrays são uma estrutura de dados fundamental para qualquer\
linguagem de programação
- Usamos arrays para armazenar valores do mesmo tipo de dados
- Em "C", os elemntos de um  array são indexados a partir de 0.
- Onde o primeiro elemento esta no índice 0,\
e o último elemnto esta no índice -1
    - Portanto, se nosso array tiver 50 elementos, o primeiro elemento\
    esta em 0 e o último elemento esta em 49.
- Existem três partes em uma declaração de array:
    - Um tipo, um nome, e um tamanho:
        ```c
        type name[size];

        int notas_alunos[40];

        double menu_precos[8];
        ```
- Instanciação de array
```c
// Sintax de Instanciação
bool truthtable[3] = { false, true, true };

// Sintax de elemento individual
bool truthtable[3];
truthtable[0] = false;
truthtable[1] = true;
truthtable[2] = true;
```

```c
// Especial sintax de Instanciação
// "C" reconhece o tamanhho da array pela indicação a direita
bool truthtable[] = { false, true, true };
```

- As matrizes podem consistir em mais de uma única dimensão.\
Você pode ter quantos especificadores de tamanho desejar.
```c
bool battleship[10][10];
```

- Podemos tratar cada elemento individual do array como uma variável
- Não podemos tratar matrizes inteiras como variáveis
- Não podemos, por exemplo, atribuir um array a outro array usando\
operador de atribuição
```c
int foo[5] = {1, 2, 3, 4, 5 };
int bar[5];
```
~~bar = foo~~

*Assim podemos atribuir valores de um array ao outro:*
```c
int foo[5] = {1, 2, 3, 4, 5 };
int bar[5];

for(int j = 0; j < 5; j++)
{
    bar[j] = foo[j];
}
```

- Arrays são passadas por referência (e todo o resto é passo por valor).

*Leia o código atentamente*
```c
// Declaração de funções
void set_array(int array[4]):
void set_int(int x);

// código
int main(void)
{
    int a = 10
    int b[4] = { 0, 1, 2, 3 };
    set_int(a);
    set_array(b);
    // Imprimir valor de "a" e "b"
    printf("%d %d\n", a b[0]);
}

// definição da funçao
void set_array(int array[4])
{
    array[0] = 22;
}

// definição da função
void set_int(int x)
{
     x = 22;
}


// Resultado
Saída: 10 22
a = 10 ("a" foi passado por valor)
b[0] = 22 ("b" foi passado por refêrencia)
```
