#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		printf("NOT VALID!. Usage: ./crypto step text\n");
		return 1;
	}
	int step = atoi(argv[1]);
	//printf("%d",step);
	char* text = malloc(strlen(argv[2])+1);
	//char text[strlen(argv[2])+1];
	for (int i = 0; i < strlen(argv[2]) + 1; i++)
	{
		if (argv[2][i] == '\0')
		{
			*(text + i) = argv[2][i];
			break;
		}
		*(text + i) = argv[2][i] + step;
	}
	for(int i = 0; i < strlen(argv[2]) + 1; i++)
	{
		printf("%c",*(text + i));
	}
	return 0 ;
	free(text);

}