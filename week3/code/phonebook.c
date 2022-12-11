// Uso de arrays (matrizes) com nomes e numeros
// Será usados strings para nomes e numeros
#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[2];

    // .name significa ir dentro da estrutura people
    // ...e acessar a variavel name e dar o nome de "Carter"
    people[0].name = "Carter";
    people[0].number = "+1-617-495-1000";

    people[0].name = "David";
    people[0].number = "+1-949-468-2750";

    // Modo sem typedef
    // string names[] = {"Carter", "David"};
    // string number[] = {"+1-617-495-1000", "+1-949-468-2750"};

    // Procurar por nome e numero na lista
    for (int i = 0; i < 2; i++)
    {
        // comparação (strcmp). Se nome for igual a "David"
        if (strcmp(people[i].name, "David") == 0)
        {
            // imprima o numero e retorne 0 (finalisa sem erros)
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    // imprima "not found" e retorne 1 (Finalisa com erro)
    printf("Not found\n");
    return 1;
}
