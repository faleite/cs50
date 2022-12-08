# Functions

- Funções, as vezes podem ser chamadas de: **Procedimentos, Métodos** ou **Sub-rotinas**
- Mas representam a mesma idéia

## Criando Funções

### 1. Declarar a função
- Ao declar uma função você esta dizendo ao compilador, que fara uma função\
e mostrando como ela será
- Colocar todas as declarações no topo do seu código, logo antes de começar\
a escrever a função main
- Existem três partes em uma declaração de função:
    - Tipo de retorno: Tipo de variável que a função produzirá (int, float, char e ...)
    - Nome: é como será chamada a função (Importante nomea-la de acondo com o que ela faz)
    - Lista de argumerntos: é uma lista separada por vírgulas, de todas as entradas\
    para a sua função, cada uma com um **tipo** e um **nome**
    - Escopo:
        ```c
        tipo-retorno nome(lista-argumerntos)
        ```
    - Exemplo 1:
        ```c
        // retorna a soma de dois inteiros
        int add_two_ints(int a, int b);
        ```
    - Exemplo 2:
        ```c
        // retorna a multiplicação de dois floats (dois numeros reais)
        // O ponto e vírgula indica que se trata de uma declaração de função
        float mult_two_reals(float x, float y);
        ```

### 2. Escrever a função
- O início de uma definição de função é o mesmo que a declaração da função *sem o **" ; "***
- Abre e fecha chaves abaixo da definição de função, onde sera implementada
- Exemplo 1:
  ```c
  // declaração da função
  float mult_two_reals(float x, float y);


  float mult_two_reals(float x, float y)
  {
      // escopo da função
      float product = x * y;
      // Retorno é a saída da função
      return product;
  }
  ```
- Exemplo 2 (Outra forma da mesma função acima):
  ```c
  // declaração da função
  float mult_two_reals(float x, float y);


  float mult_two_reals(float x, float y)
  {
      return x * y;
  }
  ```
- Exemplo 3:
  ```c
  int add_two_ints(int a, int b);


  int add_two_ints(int a, int b)
  {
      int sum;  // Declaração da variável
      sum = a + b  // Calculo de sum
      return sum;  // Devolver o resultado
  }
  ```
- Exemplo 4:
  ```c
  int add_two_ints(int a, int b);


  int add_two_ints(int a, int b)
  {
      int sum = a + b  // Calculo da variável
      return sum;  // Devolver o resultado
  }
  ```

### Uso da função
*Exemplo:*
```c
{
    ...

    // Chamada de função, armazenando-a na variável "z"
    int z = add_two_ints(a, b)

    // Saída do resultado
    printf("The sum of %i and %i is %i!\n", a, b, z);
}
```
