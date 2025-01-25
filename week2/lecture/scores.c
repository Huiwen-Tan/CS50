#include <cs50.h>
#include <stdio.h>

const int MIN_SCORE = 0;
const int MAX_SCORE = 100;

float calculate_sum(int numbers);
float calculate_average(float sum, int numbers);
float get_valid_score(int i);

int main(void)
{
    int numbers;
    do
    {
        numbers = get_int("How many scores do you want to average? Please enter a positive integer: ");
    }
    while (numbers < 1);
    float sum = calculate_sum(numbers);
    float average = calculate_average(sum, numbers);
    printf("The average score is %.2f\n", average);
}

float calculate_sum(int numbers)
{
    float sum = 0.0;
    for (int i = 0; i < numbers; i++)
    {
        sum += get_valid_score(i);
    }
    return sum;
}

float calculate_average(float sum, int numbers)
{
    float average = sum / (float) numbers;
    return average;
}

float get_valid_score(int i)
{
    float temp_score = get_float("Please enter score %i (0-100): ", i + 1);
    while (temp_score < MIN_SCORE || temp_score > MAX_SCORE)
        {
            printf("Valid scores must be between 0 and 100.\n");
            temp_score = get_float("Please enter score %i again: ", i + 1);
        }
    return temp_score;
}