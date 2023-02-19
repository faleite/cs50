# Makefile

- Makefile é um arquivo específico que permite organizar a compilação com\
algumas regras.

### Compliar na linha de comando
```makefile
# Faz compilação unindo dois ou mais arquivos:
# função main.c e a função fct.c
# E da o nome da compilação de "hello" com o "-o"
$ cc -o hello main.c fct.c

# Executando a compilação
$ ./hello
```
___

### Usando o Makefile
- Regras simples de compilação:
    - crie um arquivo Makefile desta forma:
```makefile
# "all:" regra padrão de congfiguração
all:
        # criando um comando do "all"
        cc -o hello main.c fct.c
```
- usar o Makefile:
```makefile
# Comando abre o Makefile encontra a primeira regra e a executa na sequência
$ make

# saida: Mostra o comando e o executa
cc -o hello main.c fct.c
```

- Podemos colocar segunda regra:
```makefile
# "all:" regra padrão de congfiguração
all:
        # criando um comando do "all"
        cc -o hello main.c fct.c
# Segunda regra
outro:
        echo olá
        echo hello
```
- Uso do Makefile com a segunda regra:
```makefile
# Comando abre o Makefile encontra a segunda regra e a executa na sequência
$ make outro

# saida: Mostra o comando e o executa
echo olá
olá
echo hello
hello
```
- No primeiro erro que o **make** encontra em uma regra de compilação,\
ela vair parar seu percurso e vai sair.
___

### Declarção de variável no Makefile
- Para declar uma variável contrariamente às regras, vamos usar\
"=" em vez de ":"
```makefile
# Variável Source
SRCS    = main.c fct.c

all:
        # Makefile substitui ${SRCS} por seu conteúdo
        cc -o hello ${SRCS}
```
___

### Compilação simples e eficaz do Makefile
```makefile
# Variável Source
SRCS    = main.c fct.c

# Objetos, transforma os arquivos .c em .o
OBJS    = ${SRCS:.c=.o}

# Ao usar o nome do arquivo na regra padrão, pedimos para ele fazer
# a linkagem somente quando precisar refazer este arquivo.
# ${OBJS} serve para dizer que é preciso dos arquivos .o para compilar
hello:  ${OBJS}
        # Makefile substitui ${OBJS} por seu conteúdo
        cc -o hello ${OBJS}
```
___

### Makefile mais detalhado
- Arquivo Makefile que compila um pequeno projeto de dois arquivos
```makefile
# Adiciona em uma variável todos os arquivos .c
SRCS    = main.c fct.c

# Substitui o arquivo .c pelo arquivo .o
OBJS    = ${SRCS:.c=.o}

# Armazena o nome do binário a ser compilado na variável NAME
NAME    = hello

# Flag gcc, gcc poder ser substituido por (cc)
CC      = cc

# Esta variável força a remoção
# Caso não haja o arquivo a ser removido, o programa segue sem msg error
RM      = rm -f

# Flags de compilação
CFLAGS  = -Wall -g

# Regra oculta para transformar .c em .o
# Essa regra não tem depêndencias, porque é apenas uma ação
# "-c" compila o arquivo .c que for inserido
# "$<" caracter especial que substitui o valor
# "-o" gera um arquivo .o
# ${<:.c=.o}  como em "OBJS", substitui o arquivo .c pelo arquivo .o
.c.o:
            ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:    ${OBJS}
            ${CC} -o ${NAME} ${OBJS}

# Regra standard
# É uma convenção fazer "make all" como default
# Neste caso "all:" vai ser dependente de NAME
all:        ${NAME}

# Regra clean, apaga os arquivos .o
# Para usá-la chamamos o comando "make clean"
clean:
            ${RM} ${OBJS}

# Regra fclean, espécie de force clean, que faz duas coisas:
# Chama a regra "clean" e em seguida apaga o binário
fclean:     clean
            ${RM} ${NAME}

# Regra que força a recompilação
# Chama "fclean" deletando a compilação
# na sequência chama "all" que faz a compilação
re:         fclean all

# O nome de uma regra pode ser o nome de um arquivo existente no diretório
# Isso pode ocasionar em um problema de ambiguidade
# Por exemplo: ao passar o comando "make clean" pode haver um arquivo
# chamado clean, enibira a ação do comando "make clean"
# Para contornar utilizamos a regra ".PHONY" chamando as nomes das regras.
.PHONY:     all clean fclean re
```

### Arquivo Makefile sem comentários:
```makefile
SRCS    = main.c fct.c

OBJS    = ${SRCS:.c=.o}

NAME    = hello

CC      = cc
RM      = rm -f

CFLAGS  = -Wall -g

.c.o:
            ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:    ${OBJS}
            ${CC} -o ${NAME} ${OBJS}

all:        ${NAME}

clean:
            ${RM} ${OBJS}
fclean:     clean
            ${RM} ${NAME}

re:         fclean all

.PHONY:     all clean fclean re
```
