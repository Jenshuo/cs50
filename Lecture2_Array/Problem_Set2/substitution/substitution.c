#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int check_26_characters(string s);
char substitute(char c, string keys);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    int check = check_26_characters(argv[1]);
    if (check == 1)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else if (check == 2)
    {
        printf("Key must contain 26 characters exactly once.\n");
        return 1;
    }

    string text = get_string("plaintext:  ");
    printf("ciphertext: ");

    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        char cipher = substitute(text[i], argv[1]);
        printf("%c", cipher);
    }
    printf("\n");
}

int check_26_characters(string s)
{
    int key_table[26] = {0};

    for (int i = 0; i < 26; i++)
    {
        if (isupper((unsigned char) s[i]))
        {
            if (key_table[s[i] - 'A'] == 0)
            {
                key_table[s[i] - 'A']++;
            }
            else
            {
                return 2;
            }
        }
        else if (islower((unsigned char) s[i]))
        {
            if (key_table[s[i] - 'a'] == 0)
            {
                key_table[s[i] - 'a']++;
            }
            else
            {
                return 2;
            }
        }
        else
        {
            return 1;
        }
    }

    return 0;
}

char substitute(char c, string keys)
{
    int index;

    if (islower((unsigned char) c))
    {
        index = c - 'a';
        return tolower((unsigned char) keys[index]);
        //return islower((unsigned char) keys[index]) ? keys[index] : keys[index] + 32;
    }
    else if (isupper((unsigned char) c))
    {
        index = c - 'A';
        return toupper((unsigned char) keys[index]);
        //return isupper((unsigned char) keys[index]) ? keys[index] : keys[index] - 32;
    }
    else
    {
        return c;
    }
}
