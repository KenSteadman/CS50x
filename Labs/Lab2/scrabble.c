#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2) // return player 1 wins
    {
        printf("Player 1 wins!");
    }
    else if (score2 > score1) // return player 2 wins
    {
        printf("Player 2 wins!");
    }
    else if (score1 == score2) // return tie if values are equal
    {
        printf("Tie!");
    }

}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int score = 0; // initial score is set to 0

    int len = strlen(word); // finds length of word

    for (int i = 0; i < len; i++) // loop over and score each letter of word
    {

        if (isupper(word[i])) // score uppercase letters
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i])) // score lowercase letters
        {
            score += POINTS[word[i] - 'a'];
        }
        else
        {
            i++; // moves loop forward in case of none letter values
        }
    }
    return score;

}
