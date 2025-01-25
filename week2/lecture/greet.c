#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc > 1)
    {
        printf("Hello,");
        for (int i = 1, n = argc; i < n; i++)
        {
            printf(" ");
            printf("%s", argv[i]);
        }
        printf("!\n");
        return 0;
    }
    printf("Miss command line argument\n");
    return 1;
}