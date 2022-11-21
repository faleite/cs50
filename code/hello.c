#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // ask for username, and store in variable name
    string name = get_string("What's your name? ");
    // displays the message on the screen
    printf("hello, %s!\n", name);
}
