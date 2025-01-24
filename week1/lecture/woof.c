#include <stdio.h>
#include <cs50.h>

int get_positive_number(void);
void woof(int n);

int main(void)
{
    int times = get_positive_number();
    woof(times);
}

int get_positive_number(void)
{
    int m;
    do
    {
        m = get_int("Number: ");
    }
    while (m < 1);
    return m;
}

void woof(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("woof~\n");
    }
}
