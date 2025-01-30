#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26

int get_letter_point(char letter);
int sum_points(string answer);

// The decimal index of the letters in the ACSII table
const int ASCII_DEC_A = 65;
const int ASCII_DEC_Z = 90;
// A point table for the letters of the alphabet
int point[ALPHABET_SIZE] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                            1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    string player_1 = get_string("Player 1: ");
    string player_2 = get_string("Player 2: ");
    int total_point_1 = sum_points(player_1);
    int total_point_2 = sum_points(player_2);
    if (total_point_1 > total_point_2)
    {
        printf("Player 1 wins!\n");
    }
    else if (total_point_1 < total_point_2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Score the point for each input letter
int get_letter_point(char letter)
{
    // Assign points to input letters based on their position in the alphabet
    for (int i = 0, LETTER = toupper(letter); i < ALPHABET_SIZE;
         i++) // Convert the answers to uppercase to ensure case insensitivity
    {
        if (LETTER == ASCII_DEC_A + i)
        {
            return point[i];
        }
    }
    return 0; // No points are given for non-alphabetic characters
}

// Calculate the total point by adding the points for each letter in the answer
int sum_points(string answer)
{
    int total_point = 0;
    for (int i = 0, n = strlen(answer); i < n; i++)
    {
        total_point += get_letter_point(answer[i]);
    }
    return total_point;
}