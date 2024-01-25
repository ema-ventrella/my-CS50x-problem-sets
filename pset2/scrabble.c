#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Constants
const int point[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
const char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                           'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

// Prototypes
string referee(string one, string two);
int check(string sentence);

// Main
int main(void)
{
    // Create an arry where put the words
    string word[2];

    // Get the words from the players
    word[0] = get_string("Player 1: ");
    word[1] = get_string("Player 2: ");

    // Obtain the winner
    string winner = referee(word[0], word[1]);

    // Print the winner
    printf("%s\n", winner);
}

string referee(string one, string two)
{
    // Points
    int scoreboard[2] = {0, 0};

    // Updating the scores
    scoreboard[0] += check(one);
    scoreboard[1] += check(two);

    // Calcolate the winner
    if (scoreboard[0] > scoreboard[1])
    {
        return "Player 1 wins!";
    }
    else if (scoreboard[0] < scoreboard[1])
    {
        return "Player 2 wins!";
    }
    return "Tie!";
}

int check(string sentence)
{
    // Result variable
    int value = 0;

    // For any char
    for (int i = 0, length = strlen(sentence); i < length; i++)
    {

        // Make all in lowercase
        char lower_sentence = tolower(sentence[i]);

        // When lower_sentence == alphabet[e], break
        for (int e = 0; e < 26; e++)
        {
            if (lower_sentence == alphabet[e])
            {
                value += point[e];
                break;
            }
        }
    }
    // Return the Result
    return value;
}