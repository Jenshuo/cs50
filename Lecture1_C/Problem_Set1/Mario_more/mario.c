#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_raw(int num, char symbol);

int main()
{
    int height;

    // Get height
    height = get_height();

    // Print brick
    for (int i = 0; i < height; i++)
    {
        // space + brick == height
        int brick = i + 1;
        int space = height - i - 1;

        // print space, brick, two space, brick and next line
        print_raw(space, ' ');
        print_raw(brick, '#');
        print_raw(2, ' ');
        print_raw(brick, '#');
        printf("\n");
    }
}

int get_height(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    } 
    while (h < 1);
    return h;
}

void print_raw(int num, char symbol)
{
    for (int i = 0; i < num; i++)
    {
        printf("%c", symbol);
    }
}
