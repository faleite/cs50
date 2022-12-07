#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>
#include <stdio.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Get the key (expected int)
    // Make sure program was run with just one command-line argument
    if (argc > 2 || argc < 2)
    {
        printf("Usage: ./Caesar key\n");
        return 1;
    }
    // Make sure program was run just digits
    if (only_digits(argv[1]) == 1)
    {
        printf("Usage: ./Caesar key\n");
        return 1;
    }

    // Convert a string to a int
    int chave = atoi(argv[1]);

    // Get the Plaintext
    string s = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        printf("%c", rotate(s[i], chave));
    }
    printf("\n");
}

// Converts a string into a number
bool only_digits(string s)
{
    int counter = 0;

    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (isdigit(s[i]))
        {
            counter += 1;
        }
        if (counter == len)
        {
            return 0;
        }
    }
    return s;
}

// Covert ASCII to alphabetical index
char rotate(char c, int n)
{
    if (isalpha(c))
    {
        if (isupper(c))
        {
            c -= 'A';
            c = (c + n) % 26;
            c += 'A';
        }
        if (islower(c))
        {
            c -= 'a';
            c = (c + n) % 26;
            c += 'a';
        }
    }
    return c;
}
