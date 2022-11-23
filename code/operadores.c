// Operadores aritiméticos básicos
#include <stdio.h>

int main()
{
    int a = 7, b = 3;
    int som, dif, pro, quo;

    // soma
    som = a + b;

    // diferença
    dif = a - b;

    // Proeficiencia**
    pro = a * b;

    // quociente (em "C" o operador de divisão não mostra o float)
    quo = a / 2; // 7 / 2 = 3 (3.5)

    printf("som %d\n", som);
    printf("dif %d\n",dif);
    printf("pro %d\n", pro);
    printf("quo %d\n", quo);

    return 0;
}
