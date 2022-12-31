# Defining Custom Types
## Definindo tipos de dados personalizados
- A palavra-chave C typedef fornece uma maneira de criar um nome abreviado ou\
reescrito para tipos de dados.
- A ideia básica é primeiro definir um tipo da maneira normal e, em seguida,\
apelidá-lo para outra coisa.

<h3 align="center">typedef old_name new_name;</h3>
<h3 align="center">typedef unsigned char byte;</h3>
<h3 align="center">typedef char * string;</h3>

- Você também pode pegar estruturas longas e usar **typedef** para criar algo\
muito mais curto

```c
struct car  // definindo um carro
{
int year;
char model[10];
char plate[7];
int odometer;
double engine_size;
};
// posso chamar "typedef struct car" de "car_t"
typedef struct car car_t;
```
- Forma alternativa:
```c
typedef struct car  // antigo nome
{
int year;
char model[10];
char plate[7];
int odometer;
double engine_size;
};
// posso chamar "typedef struct car" de "car_t"
car_t;  // novo nome
```

```c
// variable declaration
// ao invez de usar:
struct car mycar;
// posso usar:
car_t mycar;

// field accessing (campo de acesso)
mycar.year = 2011;
strcpy(mycar.plate, “CS50”);
mycar.odometer = 50505;
```
