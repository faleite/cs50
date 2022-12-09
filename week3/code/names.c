// código de pesquisa linear
 #include <cs50.h>
 #include <stdio.h>
 #include <string.h>

 int main(void)
 {
    // names é uma matriz, e seu tamanho é classificado de acordo
    // ...com o que há entre as chaves {}
    string names[] = {"Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"};

    // percorre item a item por toda a matriz
    for (int i = 0; i < 7; i++)
    {
        // Não podemos comparar strings diretamente em C
        // ...pois não é um tipo embutido na linguagem
        // string é uma matriz de muitos caracteres
        // para comparar strings usamos a função strcmp
        // ...da biblioteca string.h
        if (strcmp(names[i], "Ron") == 0)
        {
            // se encontrado imprima
            printf("Found\n");
            // indica sucesso
            return 0;
        }
    }
    // Após passar por todas a matriz verifincado se há a string "Ron"
    // retornamos 1, para indicar um código de erro
    printf("Not found\n");
    return 1;
 }
