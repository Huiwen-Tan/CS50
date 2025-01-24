#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char c = get_char("Input char: ");
    printf("Output char: %c\n", c);

    double d = get_double("Input double: ");
    printf("Output double: %f\n", d);

    float f = get_float("Input float: ");
    printf("Output float: %f\n", f);

    int i = get_int("Input int: ");
    printf("Output int: %i\n", i);

    long l = get_long("Input long: ");
    printf("Output long: %li\n", l);

    string s = get_string("Input string: ");
    printf("Output string: %s\n", s);
}
