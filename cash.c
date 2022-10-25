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
    //printf("Cents = %i\n", cents); test
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
    //printf("cents = %i\n", cents); //test
    //printf("quarters = %i\n", quarters); //test
    //printf("dimes = %i\n", dimes); //test
    //printf("nickels = %i\n", nickels); //test
    //printf("pennies = %i\n", pennies); //test
}

int get_cents(void)
{
    int cents = -1;
    do
    {
        cents = get_int("Change owed: ");
    }
    while(cents < 0);
    return cents;
}

int calculate_quarters(int cents)
{
    int quarters = 0;
    if(cents >= 25)
    {
        do
        {
            ++quarters; //add a quarter
        }
        while((cents - (25 * quarters)) >= 25); //check if remainder is greater than 25
    }
    return quarters;
}

int calculate_dimes(int cents)
{
    int dimes = 0;
    if(cents >= 10)
    {
        do
        {
            ++dimes; //add a dimes
        }
        while((cents - (10 * dimes)) >= 10); //check if remainder is greater than 10
    }
    return dimes;
}

int calculate_nickels(int cents)
{
    int nickels = 0;
    if(cents >= 5)
    {
        do
        {
            ++nickels; //add a nickels
        }
        while((cents - (5 * nickels)) >= 5); //check if remainder is greater than 10
    }
    return nickels;
}

int calculate_pennies(int cents)
{
    int pennies = 0;
    if(cents >= 1)
    {
        do
        {
            ++pennies; //add a pennies
        }
        while((cents - (1 * pennies)) >= 1); //check if remainder is greater than 1
    }
    return pennies;
}
