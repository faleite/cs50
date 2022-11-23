/* Função "scanf" armazena entrada do usuário a uma varaiável */
#include <stdio.h>

int main()
{
    // varaiável int a ser armazenada valor do usuário
    int idade;

    // mensagem a ser mostrada no ecrã
    printf("digite sua idade: ");

    // armazena entrada do usuário na varaiável
    scanf("%d", &idade);

    printf("Você digitou %d \n", idade);
}
