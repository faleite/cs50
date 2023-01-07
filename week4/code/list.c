#include <stdio.h>
#include <stdlib.h>

// 2.
int main(void)
{
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // ...

    // int *tmp = malloc(4 * sizeof(int));
    int *tmp = realloc(list, 4 * sizeof(int));
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }

    // for (int i = 0; i < 3; i++)
    // {
    //     tmp[i] = list[i];
    // }

    list = tmp;
    // tmp[3] = 4;
    list[3] = 4;

    // free(list);

    // list == tmp;

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    free(list);
    return 0;
}

// 1.
// int main(void)
// {
//     int list[3];

//     list[0] = 1;
//     list[1] = 2;
//     list[2] = 3;

//     for (int i = 0; i < 3; i++)
//     {
//         printf("%i\n", list[i]);
//     }
// }
