# File Pointers
### Arquivos de ponteiros
- A capacidade de ler e gravar dados em arquivos é o principal meio de\
armazenar **dados persistentes**, dados que não desaparecem quando o programa\
para de funcionar.
- A abstração de arquivos que C fornece é implementada em uma estrutura de\
dados conhecida como **FILE**.
    - Quase universalmente ao trabalhar com arquivos, usaremos ponteiros para\
    eles, __FILE*__.
___

- Todas as funções de manipulação de arquivos vivem em stdio.h.
    - Todos eles aceitam FILE* como um de seus parâmetros, exceto a função\
    fopen(), que é usada para obter um ponteiro de arquivo em primeiro lugar.
- Algumas das funções de entrada/saída (E/S) de arquivo mais comuns com as\
quais trabalharemos são:

fopen() | fclose() | fgetc() | fputc() | fread() | fwrite() |
--------|----------|---------|---------|---------|----------|
___

- fopen()
    - Abre um arquivo e retorna um ponteiro de arquivo para ele.
    - Sempre verifique o valor de retorno para garantir que você não retorne\
    NULL.

***Exemplos:***

```c
FILE* ptr = fopen(<filename>, <operation>);
```
***read:***
```c
// Aqui obtemos um ponteiro de arquivo para ler as informações do file1.txt
FILE* ptr1 = fopen("file1.txt", "r"); // "r" para leitura do arquivo
```
***write:***
```c
// Aqui obtemos um ponteiro de arquivo para a escrita no file2.txt
FILE* ptr2 = fopen("file2.txt", "w"); // "w" para escrita no arquivo file2.txt
```
***append:***
```c
// Aqui obtemos um ponteiro de arquivo para a escrita no file2.txt
FILE* ptr3 = fopen("file3.txt", "a"); // "a" anexar no arquivo file2.txt
```
- A diferença entre **w**riting e **a**ppending
    - "w" apagará todo conteúdo do arquivo para fazer a escrita, caso o arquivo\
    já exista.
    - "a" ira para o final do arquivo para fazer a escrita, caso o arquivo já\
    exista e tenha algum conteúdo.
___

- fclose()
    - Fecha o arquivo apontado pelo ponteiro de arquivo fornecido.
```c
    fclose(<file pointer>);
```
```c
    fclose(ptr1);
```
___

- fgetc()
    - *file get a character*.
    - Lê e retorna o próximo caractere do arquivo apontado.
    - Obs.: A operação do ponteiro do arquivo passado como parâmetro deve ser\
    “r” para leitura, ou você sofrerá um erro.
```c
    char ch = fgetc(<file pointer>);
```
```c
    char ch = fgetc(ptr1);
```
___

- A capacidade de obter caracteres únicos de arquivos, se agrupados em um loop,\
significa que podemos ler todos os caracteres de um arquivo e imprimi-los na\
tela, um por um, essencialmente.

```c
        char ch;
        // EOF é um valor especial de stdio.h "é o caractere de fim de arquivo"
        while((ch = fgetc(ptr)) != EOF)
            printf("%c", ch);
```
- Podemos colocar isso em um arquivo chamado cat.c, após o comando “cat” do\
Linux, que basicamente faz exatamente isso.
___

- fputc()
    - Grava ou acrescenta o caractere especificado ao arquivo apontado.
    - Obs.: A operação do ponteiro do arquivo passado como parâmetro deve ser\
    “w” para escrever ou “a” para anexar, ou você sofrerá um erro.
```c
            fputc(<character>, <file pointer>);
```
```c
            fputc('A', ptr2);
```
```c
            fputc('!', ptr3);
```
___

- Agora podemos ler caracteres de arquivos e escrever caracteres neles. Vamos\
estender nosso exemplo anterior para copiar um arquivo para outro, em vez de\
imprimir na tela.
```c
            char ch;
            while((ch = fgetc(ptr)) != EOF)
                // printf("%c", ch);
                fputc(ch, ptr2);
```

- Podemos colocar isso em um arquivo chamado cp.c, após o comando Linux “cp”\
que basicamente faz exatamente isso.
___

- fread()
    - Lê <qty> unidades de tamanho <size> do arquivo apontado e as armazena na\
    memória em um buffer (geralmente um array) apontado por \<buffer>.
    - Obs.: A operação do ponteiro do arquivo passado como parâmetro deve ser\
    “r” para leitura, ou você sofrerá um erro.
```c
        fread(<buffer>, <size>, <qty>, <file pointer>);
```
```c
        int arr[10];
        fread(arr, sizeof(int), 10, ptr);
```
```c
        double* arr2 = malloc(sizeof(double) * 80);
        fread(arr2, sizeof(double), 80, ptr);
```
```c
        char c;
        // "char c" não é um ponteiro, para usarmos fread()...
        // precisamos do endereço de c (&c)
        fread(&c, sizeof(char), 1, ptr);
```
___

- fwrite()
    - Grava unidades <qty> de tamanho <tamanho> no arquivo apontado, lendo-as\
    de um buffer (geralmente um array) apontado por \<buffer>.
    - Obs.: A operação do ponteiro do arquivo passado como parâmetro deve ser\
    “w” para escrever ou “a” para anexar, ou você sofrerá um erro.
```c
        fwrite(<buffer>, <size>, <qty>, <file pointer>);
```
```c
        int arr[10];
        fwrite(arr, sizeof(int), 10, ptr);
```
```c
        double* arr2 = malloc(sizeof(double) * 80);
        fwrite(arr2, sizeof(double), 80, ptr);
```
```c
        char c;
        // "char c" não é um ponteiro, para usarmos fwrite()...
        // precisamos do endereço de c (&c)
        fwrite(&c, sizeof(char), 1, ptr);
```
___

- Muitas outras funções úteis estão disponíveis em stdio.h para você trabalhar.\
Aqui estão alguns dos que você pode achar úteis!

Função | Descrição |
:-----:|-----------|
fgets()| Lê uma string completa de um arquivo.
fputs()| Grava uma string completa em um arquivo.
fprintf()| Grava uma string formatada em um arquivo.
fseek()| Permite retroceder ou avançar rapidamente em um arquivo.
ftell()| Informa em que posição (byte) você está dentro de um arquivo.
feof() | Informa se você leu até o final de um arquivo.
ferror()| Indica se ocorreu um erro ao trabalhar com um arquivo.
