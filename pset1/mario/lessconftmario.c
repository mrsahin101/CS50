#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int height=0;
    do
    {
        height=get_int("Height:");
    }
    while((height<1) || (height >8));

    for(int i =0;i<height;i++)
    {
        for(int j=0;j<i+1;j++)
        {
            printf("#");
        }
        printf("\n");
    }
}