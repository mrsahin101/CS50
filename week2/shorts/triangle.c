#include <stdio.h>
#include <cs50.h>

bool valid_triangle(int x, int y, int z);

int main(void)
{
    int number1 = 0, number2 = 0, number3 = 0;

    do
    {
        number1 = get_int("Number1:");
    }
    while(number1 <= 0);
    do
    {
        number2 = get_int("Number1:");
    }
    while(number2 <= 0);
    do
    {
        number3 = get_int("Number1:");
    }
    while(number3 <= 0);

    bool output = valid_triangle(number1, number2, number3);
    printf("%x",output);
}

bool valid_triangle(int x, int y, int z)
{
    if (x + y <= z )
    {
        return false;
    }
    if (y + z <= x )
    {
        return false;
    }
    if (x + z <= y )
    {
        return false;
    }
    return true;

}