#include <stdio.h>
#include <cs50.h>

int add(int a, int b)
{
    return a + b;
}

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    printf("%i\n", add(x, y));
}
