#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    long int number = 0;
    int sum[32];
    int digit[16];
    int total = 0;
    long int temp = 0;
    int temptotal = 0;
    int nDigits = 0;

    for (int i = 0; i < 35; i++)
    {
        sum[i] = 0;
        digit[i] = 0;
    }

    do
    {
        number = get_long("Credit card number:");
        nDigits = floor(log10(labs(number))) + 1 ;
        if (nDigits < 13)
        {
            printf("INVALID\n");
            return 0;
        }
    }
    while (nDigits < 13);
    temp = number;
    for (int i = 0; i < 17; i++)
    {
        digit[i] = temp % 10;
        temp = temp / 10;
    }
    for (int i = 1; i < 17; i += 2)
    {
        if (digit[i] * 2 >= 10)
        {
            sum[i - 1] = (digit[i] * 2) % 10;
            sum[i] = (digit[i] * 2 / 10);
        }
        else
        {
            sum[i - 1] = digit[i] * 2;
        }
    }
    for (int i = 0; i < 32; i++)
    {
        temptotal += sum[i];
    }
    for (int i = 0; i < 16; i += 2)
    {
        total += digit[i];
    }
    total = total + temptotal;
    if (total % 10 == 0)
    {
        if ((digit[14] != 0) && (digit[14] == 3) && (digit[13] == 4 || digit[13] == 7))
        {
            printf("AMEX\n");
        }
        else if ((digit[15] != 0) && (digit[15] == 5) && ((digit[14] == 1) || (digit[14] == 2) || (digit[14] == 3) || (digit[14] == 4)
                 || (digit[14] == 5)))
        {
            printf("MASTERCARD\n");
        }
        else if ((digit[12] == 4 || digit[13] == 4 || digit[14] == 4) || digit[15] == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
