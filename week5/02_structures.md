# Structures
## Estruturas

- As estruturas fornecem uma maneira de unificar várias variáveis de tipos\
diferentes em um único novo tipo de variável, ao qual pode ser atribuído seu\
próprio nome de tipo.
- Usamos estruturas (structs) para agrupar elementos de uma variedade de tipos\
de dados que possuem uma conexão lógica.
- Pense em uma estrutura como uma “super-variável”.
```c
struct car
{
int year;
char model[10];
char plate[7];
int odometer;
double engine_size;
};  // ponto e virgula completa a definição de estruct car
```
___

- Depois de definirmos uma estrutura, o que normalmente fazemos em arquivos .h\
separados ou sobre nossos programas fora de qualquer função, criamos efetivamente\
um novo tipo.
- Isso significa que podemos criar variáveis desse tipo usando a sintaxe familiar.
- Também podemos acessar os vários **fields** (campos) (também conhecidos como\
**members** (membros)) da estrutura usando o operador ponto (**.**)
```c
// variable declaration
struct car mycar; // struct car é o tipo, e mycar é a variável

// field accessing
mycar.year = 2011;
strcpy(mycar.plate, “CS50”);  // Copia a string "CS50" para a variável mycar.plate
mycar.odometer = 50505;
```
___

- Estruturas, como variáveis de todos os outros tipos de dados, não precisam ser\
criadas na pilha. Podemos alocar estruturas dinamicamente em tempo de execução,\
se nosso programa exigir.
- Para acessar os campos de nossas estruturas nessa situação, primeiro precisamos\
desreferenciar o ponteiro para a estrutura, e então podemos acessar seus campos.
```c
// variable declaration
struct car *mycar = malloc(sizeof(struct car));  // alocação de forma dinâmica
```
```c
// field accessing
(*mycar).year = 2011;
strcpy((*mycar).plate, “CS50”);
(*mycar).odometer = 50505;
```
___

- Isso é um pouco chato. E, como você pode esperar, há um caminho mais curto!
- O operador de seta (**->**) facilita esse processo. É um operador que faz duas\
coisas seguidas:
    - Primeiro, **desreferencia** o ponteiro do lado esquerdo do operador.
    - Segundo, **acessa** o campo ao lado direito do operador.
```c
// variable declaration
struct car *mycar = malloc(sizeof(struct car));
// field accessing
(*mycar).year = 2011;
strcpy((*mycar).plate, “CS50”);
(*mycar).odometer = 50505;
```
```c
// variable declaration
struct car *mycar = malloc(sizeof(struct car));
// field accessing
mycar->year = 2011;
strcpy(mycar->plate, “CS50”);
mycar->odometer = 50505;
```
