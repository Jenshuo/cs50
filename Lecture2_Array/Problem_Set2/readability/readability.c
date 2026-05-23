#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int letters;
    int words;
    int sentences;
} Read_Info;

Read_Info count_read_info(string text);

int main(void)
{
    string text = get_string("Text: ");

    Read_Info read_info = count_read_info(text);

    float L = ((float) read_info.letters / (float) read_info.words) * 100;
    float S = ((float) read_info.sentences / (float) read_info.words) * 100;

    // Compute Coleman-Liau index
    int index = (int) round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

Read_Info count_read_info(string text)
{
    Read_Info read_info = {0, 0, 0};

    int length = strlen(text);
    bool in_word = false;

    for (int i = 0; i < length; i++)
    {
        // Check letters
        if (isalpha((unsigned char) text[i]))
        {
            read_info.letters++;
        }

        // Check words : when space -> not space is a word
        if (text[i] == ' ')
        {
            in_word = false;
        }
        else if (!in_word)
        {
            in_word = true;
            read_info.words++;
        }

        // Check sentences
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            read_info.sentences++;
        }
    }

    return read_info;
}