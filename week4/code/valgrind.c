// Memory check, a memory error detector
// Use: valgrind ./file_name
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // take up memory for var 'x' (3 * size of int)
    int *x = malloc(3 * sizeof(int));
    x[0] = 72;  // store int in array
    x[1] = 73;
    x[2] = 33;
    free(x);  // for free allocated memory
}
