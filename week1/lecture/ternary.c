#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: ");
    char y = (x <= 6 && x > 0) ? 'T' : 'F';
    printf("%c\n", y);
}