#include <cs50.h>
#include <stdio.h>

const int amex_length = 15;
const int amex_prefix_1 = 34;
const int amex_prefix_2 = 37;
const int mastercard_length = 16;
const int mastercard_prefix_smallest = 51;
const int mastercard_prefix_largest = 55;
const int visa_length_1 = 13;
const int visa_length_2 = 16;
const int visa_prefix = 4;

void validate_credit_card(long card_number);
void check_card_type(int length, int prefix_1, int prefix_2);

int main(void)
{
    long card_number;
    do
    {
        card_number = get_long("Number: ");
    }
    while (card_number < 1);
    validate_credit_card(card_number);
}

void validate_credit_card(long card_number)
{
    long number = card_number;
    int checksum = 0;
    int length = 0;
    int prefix_1 = 0;
    int prefix_2 = 0;
    while (number > 0)
    {
        int digit = number % 10;
        if (length % 2 == 0)
        {
            checksum += digit;
        }
        else
        {
            checksum += (digit * 2) % 10 + (digit * 2) / 10;
        }
        length++;
        if (number < 100 && number >= 10)
        {
            prefix_2 = number;
        }
        if (number < 10)
        {
            prefix_1 = number;
        }
        number /= 10;
    }
    if (checksum % 10 == 0)
    {
        check_card_type(length, prefix_1, prefix_2);
    }
    else
    {
        printf("INVALID\n");
    }
}

void check_card_type(int length, int prefix_1, int prefix_2)
{
    // check American Express
    if (length == amex_length && (prefix_2 == amex_prefix_1 || prefix_2 == amex_prefix_2))
    {
        printf("AMEX\n");
    }
    // check MasterCard
    else if (length == mastercard_length && prefix_2 >= mastercard_prefix_smallest &&
             prefix_2 <= mastercard_prefix_largest)
    {
        printf("MASTERCARD\n");
    }
    // check Visa
    else if (prefix_1 == visa_prefix && (length == visa_length_1 || length == visa_length_2))
    {
        printf("VISA\n");
    }
    // invalid
    else
    {
        printf("INVALID\n");
    }
}