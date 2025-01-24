#include <cs50.h>
#include <stdio.h>

void cash(int n);

int main(void)
{
    int change_owed;
    do
    {
        change_owed = get_int("Change owed: ");
    }
    while (change_owed < 0);
    cash(change_owed);
}

void cash(int n)
{
    int m = n / 25 + (n % 25) / 10 + ((n % 25) % 10) / 5 + ((n % 25) % 10) % 5;
    printf("%i\n", m);
}