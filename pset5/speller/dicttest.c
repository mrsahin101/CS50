#include <stdio.h>
#include <string.h>
int main(void)
{
    char buffer[50];
    FILE* file = fopen("./dictionaries/large", "r");
    FILE* output = fopen("deneme.txt","w");
    if (file == NULL)
    {
        printf("couldnt load!");
        return 1;
    }
    while (fscanf(file,"%s",buffer) != EOF)
    {
        if (strlen(buffer) <= 3)
        {
            fprintf(output,"%s\n",buffer);
        }
    }
    fclose(file);
    fclose(output);
}