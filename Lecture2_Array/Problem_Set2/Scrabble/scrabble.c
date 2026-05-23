#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int POINTS[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                        1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string pattern);

int main(void)
{

    string s1 = get_string("Player 1: ");
    string s2 = get_string("Player 2: ");

    int score1 = compute_score(s1);
    int score2 = compute_score(s2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string pattern)
{
    int score = 0;

    int length = strlen(pattern);

    for (int i = 0; i < length; i++)
    {
        char c = toupper((unsigned char) pattern[i]);

        if (c >= 'A' && c <= 'Z')
        {
            score += POINTS[c - 'A'];
        }
    }

    return score;
}
