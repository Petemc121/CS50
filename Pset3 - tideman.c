#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{

    for(int i = 0; i < candidate_count; i++) {

        if (strcmp(name,candidates[i]) == 0) {
            ranks[rank] = i;
            return true;
        }

    }

    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{


    for (int i = 0; i < candidate_count; i++)
    {

        for (int j = i + 1; j < candidate_count; j++)
        {


               preferences[ranks[i]][ranks[j]]++;

        }
    }


    for (int i = 0; i < candidate_count; i++)
    {

        for (int j = 0; j < candidate_count; j++)
        {


             printf("%i", preferences[i][j]);

        }

         printf("\n");
    }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
       for (int i = 0; i < candidate_count; i++)
    {

        for (int j = i; j < candidate_count; j++)
        {


             if (preferences[i][j] > preferences[j][i]) {

                 pairs[pair_count].winner = i;
                 pairs[pair_count].loser = j;
                  printf("winner: %i\n", pairs[pair_count].winner);
                    printf("loser: %i\n", pairs[pair_count].loser);
                 pair_count++;



             } else if (preferences[j][i] > preferences[i][j]) {

                 pairs[pair_count].winner = j;
                 pairs[pair_count].loser = i;
                  printf("winner: %i\n", pairs[pair_count].winner);
                    printf("loser: %i\n", pairs[pair_count].loser);
                 pair_count++;



             }

        }


    }

    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{

    for (int i = 0; i < pair_count - 1; i++)
    {

        if ((preferences[pairs[i].winner] - preferences[pairs[i].loser]) < (preferences[pairs[i + 1].winner] - preferences[pairs[i + 1].loser]) )
        {
            pair tmp = pairs[i];
            pairs[i] = pairs[i+1];
            pairs[i+1] = tmp;
        }
    }


 for (int i = 0; i < pair_count; i++) {
        printf("%i", pairs[i].winner);
        printf("%i\n", pairs[i].loser);
    }



}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{

int winner;

                for (int k = 0; k < pair_count; k++) {


                if (pairs[k].loser != winner) {

           locked[pairs[k].winner][pairs[k].loser] = true;

                }

            if (k == 0)
            {
                winner = pairs[k].winner;
            }


        }


      for (int i = 0; i < candidate_count; i++)
    {


        for (int j = 0; j < candidate_count; j++)
        {


            printf("%d", locked[i][j]);

        }

        printf("\n");

    }


    return;
}

// Print the winner of the election
void print_winner(void)
{

   int winnerArray[MAX]

    for (int i = 0; i < candidate_count; i++)
    {
            int winNum;

        for (int j = 0; j < candidate_count; j++)
        {


           if (locked[i][j] == true) {
               winNum++
           }

        }

        winnerArray[i] = winNum;

    }

    int highest;
    int ties;

    for (int i = 0; i < candidate_count; i++)
    {
        if (i = 0) {
            highest = winnerArray[i];
        } else if (winnerArray[i] > highest)
        {
            highest = winnerArray[i]
        } else if (winnerArray == highest )
        {
            ties++
        }
    }


    if (ties !== 0) {
        for
    } else {

    for (int i = 0; i < candidate_count; i ++)
    {
        if (winnerArray[i] == highest) {
            printf("%s", candidates[i]);
        }
    }
}

    return;
}

