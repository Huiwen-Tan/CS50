#include <cs50.h>
#include <stdio.h>

void block(int m);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1);
    block(height);
}

void block(int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m - i - 1; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}