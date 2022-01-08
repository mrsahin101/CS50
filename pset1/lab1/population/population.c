#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int str_size=0,end_size=0,years=0;;
    do
    {
        str_size=get_int("Starting Size:");
    }
    while(str_size<9);
    // TODO: Prompt for end size
    do
    {
        end_size=get_int("Ending Size:");
    }
    while(str_size>end_size);
    // TODO: Calculate number of years until we reach threshold
    while(str_size<end_size)
    {
        str_size= str_size + (str_size/3) - (str_size/4);
        years++;
    }
    // TODO: Print number of years
    printf("It will take %i years to get that from %i population to %i population\n",years,str_size,end_size);
}