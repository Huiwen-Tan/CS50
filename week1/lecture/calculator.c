#include <cs50.h>
#include <stdio.h>

long positive_exponentiation(int a, int b)
{
    long m = 1;
    for (int i = 0; i < b; i++)
    {
        m = m * a;
    }
    return m;
}

int main(void)
{
    int base = get_int("base: ");
    int exponent;
    do
    {
        exponent = get_int("exponent: ");
    }
    while (exponent < 0);

    printf("%li\n", positive_exponentiation(base, exponent));
}
