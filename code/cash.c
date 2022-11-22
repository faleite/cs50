#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    // prompts the user for a number of cents
    int cents;
    do
    {
        cents = get_int("Enter a number of cents: ");
    }
    while (cents < 0);
    return cents;
}

int calculate_quarters(int cents)
{
    // how many of 25
    int how_quarters = cents / 25;
    return how_quarters;
}

int calculate_dimes(int cents)
{
    // how many of 10
    int how_dimes = cents / 10;
    return how_dimes;
}

int calculate_nickels(int cents)
{
    // how many of 5
    int how_nickels = cents / 5;
    return how_nickels;
}

int calculate_pennies(int cents)
{
    // how many of 1
    int how_pennies = cents / 1;
    return how_pennies;
}
