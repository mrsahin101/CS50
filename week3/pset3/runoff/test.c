#include <stdio.h>
#include <math.h>
int main ()
{
	int voter_count = 100;
	float temp = (float)voter_count/2;
    float temp1 = ceil(temp);
    int win_condition = round(temp1);
    printf("%d",win_condition);
}