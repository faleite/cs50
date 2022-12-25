#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // for each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // check if name is the same as any candidate
        if (strcmp(name, candidates[i].name) == 0)
        {
            // add candidate in a rank
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // for each voter
    for (int i = 0; i < voter_count; i++)
    {
        // and for each candidate
        for (int j = 0; j < candidate_count; j++)
        {
            // rank of the voter
            int candidate = preferences[i][j];

            // if the candidate was not eliminated
            if (candidates[candidate].eliminated == false)
            {
                // add a vote
                candidates[candidate].votes += 1;
                break;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // for each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // if the vote is greater than half of the total votes
        if (candidates[i].votes > voter_count / 2)
        {
            // show the win
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // variable for add the minor value
    int min = voter_count;

    // for each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // if vote is less than the 'var min' and the candidate was not eliminated
        if (candidates[i].votes < min && candidates[i].eliminated == false)
        {
            // add minor vote in a var min
            min = candidates[i].votes;
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // counter for tie
    int tie = 0;
    // counter for on run
    int onrun = 0;

    // for each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // if candidate was not eliminated, and vote is equal the 'var min'
        if (candidates[i].eliminated == false &&
            candidates[i].votes == min)
        {
            // add 1 in a var
            tie += 1;
            onrun += 1;
        }
        // Else if just candidate was not eliminated
        else if (candidates[i].eliminated == false)
        {
            // add 1 in a var
            onrun += 1;
        }
    }
    // if var tie is equal the va onrun
    if (tie == onrun)
    {
        return true;
    }
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // for each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // if vote is equal the var min
        if (candidates[i].votes == min)
        {
            // change status candidate eliminated for true
            candidates[i].eliminated = true;
        }
    }
    return;
}
