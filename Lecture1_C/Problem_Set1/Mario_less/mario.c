#include <cs50.h>
#include <stdio.h>

void print_raw(int space, int brick);

int main()
{
    int height;

    // Get height
    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0);

    for (int i = 0; i < height; i++)
    {
        print_raw(height - i - 1, i + 1);
    }
}

void print_raw(int space, int brick)
{
    // Print space ""
    for (int i = 0; i < space; i++)
    {
        printf(" ");
    }

    // Print brick "#"
    for (int j = 0; j < brick; j++)
    {
        printf("#");
    }

    printf("\n");
}