#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int KEY_LENGTH = 26; // The key length is limited to 26 characters

int encrypt_character(char p, string key);
bool validate_key(string input);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (validate_key(argv[1]) == false)
    {
        return 1;
    }
    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", encrypt_character(plaintext[i], argv[1]));
    }
    printf("\n");
    return 0;
}

// Encrypt the plaintext according to a case-insensitive key
// Preserve the case of the plaintext
int encrypt_character(char p, string key)
{
    int c, position;
    if (isalpha(p))
    {
        if (isupper(p))
        {
            position = p - 'A';
            c = toupper(key[position]);
        }
        else
        {
            position = p - 'a';
            c = tolower(key[position]);
        }
    }
    else
    {
        c = p;
    }
    return c;
}

// Verify that the key is valid
// Valid key contains only 26 non-repeating alphabetical character (case insensitive)
bool validate_key(string input)
{
    if (strlen(input) != KEY_LENGTH)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }
    for (int i = 0; i < KEY_LENGTH; i++)
    {
        if (isalpha(input[i]) == 0)
        {
            printf("Key must only contain alphabetic characters.\n");
            return false;
        }
        for (int j = 0; j < i; j++)
        {
            if (toupper(input[j]) == toupper(input[i]))
            {
                printf("Key must not contain repeated characters.\n");
                return false;
            }
        }
    }
    return true;
}