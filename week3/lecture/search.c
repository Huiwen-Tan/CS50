#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {50, 200, 10, 100, 20, 5, 1};
    int n = get_int("Number: ");
    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}