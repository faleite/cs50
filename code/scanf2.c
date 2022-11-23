#include <stdio.h>

int main()
{
    int meuInt;
    char meuChar;

    printf("meuInt: ");
    scanf("%d", &meuInt);

    // Solução para entrada segunda da variável "meuChar"
    fflush(stdin);

    printf("meuChar: ");
    scanf("%c", &meuChar);

    return 0;
}
