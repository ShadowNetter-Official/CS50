#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates -- define max number of possible candidates
#define MAX 9

// Candidates have name and vote count -- define struct "candidate" with name and number of votes
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates -- make an array of type candidate and of size MAX (9)
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates -- for every argument excluding plurality, add argument to the
    // array if it does not surpass the max number of candidates allowed
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }
    // get number of voters
    int voter_count = get_int("Number of voters: ");

    // Loop over all voters -- check if vote is valid with the vote function
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // check if given name is valid, if not, return false else add to vote count of name
    int strikes = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) != 0)
        {
            strikes++;
        }
        else
        {
            candidates[i].votes++;
        }
    }
    if (strikes >= candidate_count)
    {
        return false;
    }
    return true;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // get highest vote
    int highest_vote = 0;
    // for every candidate find highest vote
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > highest_vote)
        {
            highest_vote = candidates[i].votes;
        }
    }
    // check if there were any votes
    if (highest_vote > 0)
    {
        // for every candidate, find the one that matches highest vote and add to winner count
        int winner_count = 0;
        for (int j = 0; j < candidate_count; j++)
        {
            if (candidates[j].votes == highest_vote)
            {
                winner_count++;
            }
        }
        // check if there are any winners
        if (winner_count > 0)
        {
            // create array with size of number of winners
            string winners[winner_count];
            // for every candidate, find the one that matches highest vote and add to winners
            for (int k = 0; k < candidate_count; k++)
            {
                if (candidates[k].votes == highest_vote)
                {
                    if (winner_count == 1)
                    {
                        winners[0] = candidates[k].name;
                    }
                    else
                    {
                        winners[k] = candidates[k].name;
                    }
                }
            }
            // for every winner, print winner name
            for (int l = 0; l < winner_count; l++)
            {
                printf("%s\n", winners[l]);
            }
        }
    }
}
