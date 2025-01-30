#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int calculate_grade_level(string text);
int count_letters(string text);
int count_sentences(string text);
int count_words(string text);

int main(void)
{
    string text = get_string("Text: ");
    int level = calculate_grade_level(text);
    if (level < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (level >= 1 && level < 16)
    {
        printf("Grade %i\n", level);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

// Calculate the reading level according to the Coleman-Liau index
int calculate_grade_level(string text)
{
    int level = 0;
    // L is the average number of letters per 100 words in the text
    double L = count_letters(text) * 100.0 / count_words(text);
    // S is the average number of sentences per 100 words in the text
    double S = count_sentences(text) * 100.0 / count_words(text);
    // Coleman-Liau index
    double index = 0.0588 * L - 0.296 * S - 15.8;
    // Round index to the nearest level
    level = (int) round(index);
    return level;
}

// Count the number of letters in the text
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]) != 0)
        {
            letters++;
        }
    }
    return letters;
}

// Count the number of sentences in the text
int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
    return sentences;
}

// Count the number of words in the text
int count_words(string text)
{
    int words = 0, spaces = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]) != 0)
        {
            spaces++;
        }
    }
    // The number of words in a text is usually one more than the number of spaces
    words = spaces + 1;
    return words;
}