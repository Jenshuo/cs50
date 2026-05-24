#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    bool digit = only_digits(argv[1]);
    if (!digit)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    int key = atoi(argv[1]);
    string text = get_string("plaintext:  ");
    printf("ciphertext: ");

    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        char cipher = rotate(text[i], key);
        printf("%c", cipher);
    }
    printf("\n");
}

bool only_digits(string s)
{
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        if (!isdigit((unsigned char) s[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    char cipher;
    int offset;
    int rotated;

    if (isupper((unsigned char) c))
    {
        offset = c - 'A';
        rotated = (offset + n) % 26;
        cipher = 'A' + rotated;
    }
    else if (islower((unsigned char) c))
    {
        offset = c - 'a';
        rotated = (offset + n) % 26;
        cipher = 'a' + rotated;
    }
    else
    {
        cipher = c;
    }

    return cipher;
}
