#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int cents=0;
    float input=0;
    int quarters=0,dimmes=0,nickels=0,pennies=0;
    do
    {
        input=get_float("Change owed:");
    }
    while(input<=0);
    cents=round(input*100);

    while(cents>=1)
    {
        if((cents-25)>=0)
        {
            cents=cents-25;
            quarters++;
        }
        else if((cents-10)>=0)
        {
            cents=cents-10;
            dimmes++;
        }
        else if((cents-5)>=0)
        {
            cents=cents-5;
            nickels++;
        }
        else if((cents-1)>=0)
        {
            cents=cents-1;
            pennies++;
        }
    }
    printf("Quarters:%i,Dimmes:%i,Nickels:%i,Pennies:%i\n",quarters,dimmes,nickels,pennies);
}