#include <stdio.h>
#include <cs50.h>

void meow(int n)
{
    int i = 0;
    while (i < n)
    {
        printf("meow~\n");
        i++;
    }
}

void woof(int m)
{
    for (int j = 0; j < m; j++)
    {
        printf("woof~\n");
    }
}

int main(void)
{
    meow(1);
    woof(1);
}
