#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

int encrypt_character(char plaintext, int key);
bool only_digits(string input);
int rotate(char p, int k);

int main(int argc, string argv[])
{
    if (argc != 2 || only_digits(argv[1]) == false)
    {
        printf("Usage: ./caeser key\n");
        return 1;
    }
    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        int ciphertext_i = encrypt_character(plaintext[i], key);
        printf("%c", ciphertext_i);
    }
    printf("\n");
}

// Given the key, encrypt each alphabetical character of the plaintext
int encrypt_character(char plaintext, int key)
{
    int ciphertext;
    if (isalpha(plaintext) != 0)
    {
        ciphertext = rotate(plaintext, key);
    }
    else
    {
        ciphertext = plaintext;
    }
    return ciphertext;
}

// Verify that the key is pure digit
bool only_digits(string input)
{
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (isdigit(input[i]) == 0)
        {
            return false;
        }
    }
    return true;
}

// Caesar’s algorithm encrypts messages by rotating each letter by k positions
int rotate(char p, int k)
{
    int c;
    if (isupper(p))
    {
        c = (p - 'A' + k) % ALPHABET_SIZE + 'A';
    }
    else
    {
        c = (p - 'a' + k) % ALPHABET_SIZE + 'a';
    }
    return c;
}