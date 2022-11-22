#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Enter the height: ");
    }
    while (n < 1 || n > 8);

    // for each row
    for (int i = 0; i < n; i++)
    {
        for (int k = n - 2; k >= i; k--)
        {
            printf(" ");
        }
        // for each column
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // space between the stairs
        printf("  ");

        // second stairs
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
