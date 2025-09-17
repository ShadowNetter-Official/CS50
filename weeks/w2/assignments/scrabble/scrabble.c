#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int compute_score(string word);

int main(void)
{
    // get input
    string team1 = get_string("Player 1: ");
    string team2 = get_string("Player 2: ");

    // compute score
    int score1 = compute_score(team1);
    int score2 = compute_score(team2);

    // check score and output winner or tie
    if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else if (score2 < score1)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // array with 26 values, each value represents the points for a letter, in alphabetical order
    int POINTS[] = {1, 3, 3, 2, 1, 4, 2 , 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int score = 0;

    // check for each letter in input
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        // word[1] is the current letter
        // check if input is a letter
        if (isalpha(word[i]))
        {
            // convert letter to upper case and use ascii value to get index
            // example: A - A = 0 because A in ascii is 65 and so on, like this we get the point index
            int letter_index = toupper(word[i]) - 'A';
            score = score + POINTS[letter_index];
        }
    }
    return score;

}
