# Pointers
- Os ponteiros fornecem uma maneira alternativa de passar dados entre funções.
    - Lembre-se de que até aqui passamos todos os dados por valor, com uma\
    exceção.
    - Quando passamos dados por valor, passamos apenas uma cópia desses dados.
- Se usarmos ponteiros, teremos o poder de passar a própria variável real.
    - Isso significa que uma alteração feita em uma função pode afetar o que\
acontece em uma função diferente.
    - Antes isso não era possível!
---
- Antes de nos aprofundarmos no que são ponteiros e como trabalhar com eles,\
vale a pena voltar ao básico e dar uma olhada na memória do nosso computador.
- Cada arquivo em seu computador reside em sua unidade de disco, seja uma\
unidade de disco rígido (HDD) ou uma unidade de estado sólido (SSD).
- As unidades de disco são apenas espaço de armazenamento; não podemos\
trabalhar diretamente lá. A manipulação e o uso de dados só podem ocorrer na\
RAM, portanto, temos que mover os dados para lá.
- A memória RAM é basicamente uma enorme matriz de bytes de 8 bits de largura.
    - 512 MB, 1 GB, 2 GB, 4 GB…
    - Portanto, quando movemos as coisas para a memória, isso ocupa uma certa\
    quantidade de espaço.

Tipo de Dados | Tamanho (em bytes)
:------------:|:-----------------:
int | 4
char | 1
float | 4
double | 8
long long | 8
string | **???**

- De volta a essa ideia de memória como uma grande matriz de células do tamanho\
de bytes.
- Lembre-se de nossa discussão sobre arrays de que eles não são úteis apenas\
para armazenamento de informações, mas também para o chamado acesso aleatório.
    - Podemos acessar elementos individuais do array indicando qual localização\
    de índice queremos.
- Da mesma forma, cada local na memória possui um endereço.

*Exemplo de memória com 20 bytes:*
-|-|-|-|H|-|-|-|65|//|//|//|L|l|o|y|d|\0|-|-|
-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
0x0|0x1|0x2|0x3|0x4|0x5|0x6|0x7|0x8|0x9|0xA|0xB|0xC|0xD|0xE|0xF|0x10|0x11|0x12|0x13|

- char c = ‘H’ (1 bytes);
- int speedlimit = 65 (4 bytes);
- string surname = “Lloyd” (neste caso: 6 bytes);
___

#### POINTERS ARE JUST ADDRESSES
- Há apenas uma coisa crítica a ser lembrada quando começamos a trabalhar com\
ponteiros:
    - **Ponteiros são apenas endereços**
    - Os **ponteiros** são endereços para locais na memória onde as variáveis\
    residem.
- Quando começarmos a trabalhar com ponteiros, lembre-se desta alusão:
    - Se eu disser, por exemplo `int k;` no meu código, eu poso dizer que:
        - Estou deixando um espaço na memória reservado para mim
    - Ou, posso dizer:
        - Eu tenho uma *caixa* e nomeei a caixa de *k*, onde posso colocar\
        números inteiros. Isso é o que acontece quando digo `int k;`
    - Quando digo `k = 5` estou colocando *5* na caixa.
        - Função|Código|
          -----|------|
          *crie uma caixa chamada* **k**| ``int k;``|
          *coloque **5** na caixa*| ``k = 5;``
    - Se eu disser `int* pk;` estou criando uma caixa para armazenar o endereço\
    de uma caixa que guarda um inteiro.
    - Se eu disser `pk = &k;` estou colocando o endereço de `k` na caixa *pk*
    - **pk** nos dá a informação que precisamos para encontrar **k** na memória.
    ```c
    int k;  // cria uma variável do tipo inteiro
    k = 5;  // atribui o 5 a variável k
    int* pk;  // cria um ponteiro do tipo inteiro
    pk = &k;  // atribui o endereço da variável k ao ponteiro pk
    // o que podemos ver em pk, ex.: 0x80C74820
    ```
---

- Um **ponteiro**, então, é um item de dados cujo:
    - valor é um endereço de memória
    - tipo descreve os dados localizados naquele endereço de memória
- Como tal, os ponteiros permitem que estruturas de dados e/ou variáveis sejam\
compartilhadas entre funções.
- Os ponteiros tornam um ambiente de computador mais parecido com o mundo real.

---

- O ponteiro mais simples disponível para nós em C é o ponteiro NULL. Como você\
pode esperar, esse ponteiro aponta para nada (um fato que pode ser útil!)
- Quando você cria um ponteiro e não define seu valor imediatamente, deve\
**sempre** definir o valor do ponteiro como NULL.
- Você pode verificar se um ponteiro é NULL usando o operador de igualdade (**==**).

---

- Outra maneira fácil de criar um ponteiro é simplesmente **extrair** o endereço de\
uma variável já existente. Podemos fazer isso com o operador de extração de\
endereço (**&**).
- Se **x** é uma variável do tipo int, então **&x** é um ponteiro para int cujo\
valor é o endereço de **x**.
- Se **arr** é um array de doubles, então **&arr[i]** é um ponteiro-para-double\
cujo valor é o endereço do **i-ésimo** elemento de **arr**.
    - *O nome de um array, então, é na verdade apenas um ponteiro para seu\
    primeiro elemento - você tem trabalhado com ponteiros o tempo todo!*

---

- O principal objetivo de um ponteiro é nos permitir modificar ou inspecionar o\
local para o qual ele aponta.
    - Fazemos isso **desreferenciando** o ponteiro.
- Se tivermos um ponteiro para char chamado **pc**, então **\*pc** são os dados\
que residem no endereço de memória armazenado dentro da variável **pc**.

---

- Usado neste contexto, **\*** é conhecido como o **operador de desreferência.**
- Ele “vai até a referência” e acessa os dados naquele local de memória,\
permitindo que você o manipule à vontade.
- Isso é como visitar seu vizinho. Ter o endereço não é suficiente. Você\
precisa **ir até** o endereço e só então poderá interagir com eles.

---

- Você consegue adivinhar o que pode acontecer se tentarmos desreferenciar um\
ponteiro cujo valor é NULL?

<h3 align="center">Falha de segmentação</h3>

- Surpreendentemente, este é realmente um bom comportamento! Ele defende contra\
a manipulação perigosa acidental de ponteiros desconhecidos.
    - É por isso que recomendamos que você defina seus ponteiros para NULL\
    imediatamente se não os estiver definindo para um valor desejado conhecido.

---

<h3 align="center">int* p;</h3>

- O valor de **p** é um endereço.
- Podemos desreferenciar **p** com o operador **\***.
- Se o fizermos, o que encontraremos nesse local é um **int**.

---

- Mais uma coisa chata com esses *s. Eles são uma parte importante do nome do\
tipo **e** do nome da variável.
- Melhor ilustrado com um exemplo.

<h3 align="center"><s>int* px, py, pz;</s></h3>
<h3 align="center">int* pa, *pb, *pc;</h3>

---
- Quão grande é uma string?
    - string é uma matriz de caracteres
    - char* é um ponteiro onde armazenamos uma matriz de caracteres
    - char* aponta para o endereço do primeiro caractere da matriz
    - Dependendo da sua maquina pode ter 32 ou 64 bits
        - Portanto o tamanho de um char* varia entre 4 e 8 bytes
        - Assim como: int*, float*, double*. Como representado na tabela abaixo

Tipo de Dados | Tamanho (em bytes)
:------------:|:-----------------:
int | 4
char | 1
float | 4
double | 8
long long | 8
char*, int*, float*, double*, \_____* | 4 or 8
