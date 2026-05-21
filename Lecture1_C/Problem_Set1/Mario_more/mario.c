#include <cs50.h>
#include <stdio.h>

void print_raw(int num, char symbol);

int main()
{
    int height;
    int brick;
    int space;

    // Get height
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1);

    // Print brick
    for (int i = 0; i < height; i++)
    {
        // space + brick == height
        brick = i + 1;
        space = height - i - 1;

        // print space, brick, two space, brick and next line
        print_raw(space, ' ');
        print_raw(brick, '#');
        print_raw(2, ' ');
        print_raw(brick, '#');
        printf("\n");
    }
}

void print_raw(int num, char symbol)
{
    for (int i = 0; i < num; i++)
    {
        printf("%c", symbol);
    }
}
