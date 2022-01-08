#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    int i = 0, key = 0;
    string temp_argv = argv[1], input, output;

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    while ((argv[1][i]) != '\0')
    {
        if (isdigit(argv[1][i]) != 0)
        {
            i++;
        }
        /*else if (argv[1][i] == '.')
        {
            argv[1][i] = '\0';
            i++;
        }*/
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    i = 0;
    key = atoi(argv[1]);
    key = key % 26;
    input = get_string("Plain Text:");
    output = input;

    while (input[i] != '\0')
    {
        if (input[i] >= 65 && input[i] <= 90)
        {
            output[i] = (((input[i] - 65) + key) % 26) + 65;
            i++;
        }
        else if (input[i] >= 97 && input[i] <= 122)
        {
            output[i] = (((input[i] - 97) + key) % 26) + 97;
            i++;
        }
        else
        {
            output[i] = input[i];
            i++;
        }
    }
    i = 0 ;
    printf("ciphertext:%s\n", output);
    return 0;
    /*while(output[i] != '\0')
    {

    }*/
}
