#include <cs50.h>
#include <stdio.h>

typedef struct
{
    int luhn_sum;
    int digit_count;
    int start_two_digit;
    int start_one_digit;
} CardInfo;

CardInfo luhn_algo(long card_num);

int main(void)
{
    long card_num;
    CardInfo card_info;

    card_num = get_long("Number: ");

    // Calculate Luhn algo. and digit count
    card_info = luhn_algo(card_num);
    // printf("Luhn sum = %d, digit_count = %d\n", card_info.luhn_sum, card_info.digit_count);

    // Check valid or not and type of credit
    if (card_info.luhn_sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    // AMEX
    else if ((card_info.digit_count == 15) &&
             ((card_info.start_two_digit == 34) || (card_info.start_two_digit == 37)))
    {
        printf("AMEX\n");
    }
    // Master Card
    else if ((card_info.digit_count == 16) &&
             ((card_info.start_two_digit >= 51) && (card_info.start_two_digit <= 55)))
    {
        printf("MASTERCARD\n");
    }
    // VISA
    else if ((card_info.digit_count == 13 || card_info.digit_count == 16) &&
             (card_info.start_one_digit == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

CardInfo luhn_algo(long card_num)
{
    int count = 0;
    int sum = 0;

    CardInfo info;

    // Example : 4003600000000014

    while (card_num > 0)
    {

        // Get 40
        if ((card_num / 100 == 0) && (card_num / 10 > 0))
        {
            info.start_two_digit = card_num;
        }
        // Get 4
        if (card_num / 10 == 0)
        {
            info.start_one_digit = card_num;
        }

        // Get 4, 1, 0, .... 0, 6, 3, 0, 0, 4
        int digit = card_num % 10;
        card_num /= 10;

        // even (0, 2, 4, ....) add together
        if (count % 2 == 0)
        {
            // add 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0
            sum += digit;
        }
        // odd (1, 3, 5, ...) *2 and split add togegher
        else
        {
            // add 4*2 + 0*2 + 0*2 + 0*2 + 6*2 + 0*2 + 4*2
            // because 6*2 = 12 => split to 1 and 2 => + 1 + 2
            int digit_mul2 = digit * 2;
            while (digit_mul2 > 0)
            {
                sum += digit_mul2 % 10;
                digit_mul2 /= 10;
            }
        }

        // digit count
        count++;
    }

    info.digit_count = count;
    info.luhn_sum = sum;

    return info;
}