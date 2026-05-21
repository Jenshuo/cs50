#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_coins(int cents, int unit);

int main(void)
{
    int cents;
    cents = get_cents();

    int coins_total = 0;
    int coins_25;
    int coins_10;
    int coins_5;
    int coins_1;

    // Calculate coins for 4 times => Greedy algo.
    // 1st : 25 cent
    // 2nd : 10 cent
    // 3rd :  5 cent
    // 4th :  1 cent
    coins_25 = calculate_coins(cents, 25);
    cents -= coins_25 * 25;
    // cents %= 25;

    coins_10 = calculate_coins(cents, 10);
    cents -= coins_10 * 10;
    // cents %= 10;

    coins_5 = calculate_coins(cents, 5);
    cents -= coins_5 * 5;
    // cents %= 5;

    coins_1 = calculate_coins(cents, 1);
    cents -= coins_1 * 1;

    coins_total = coins_25 + coins_10 + coins_5 + coins_1;

    printf("%d\n", coins_total);
}

int get_cents(void)
{
    int cents;

    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    return cents;
}

int calculate_coins(int cents, int unit)
{
    int coins = 0;

    while (cents >= unit)
    {
        cents -= unit;
        coins++;
    }

    return coins;
}
