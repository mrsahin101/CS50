#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    char up_key[26], down_key[26];
    string plaintext, output = "ahmet";
    // checking arguments and validating the key
    if (argc != 2)
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0; i < 26; i++)
    {
        up_key[i] = toupper(argv[1][i]);
        if ((up_key[i] < 65) || (up_key[i] > 90))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        down_key[i] = tolower(argv[1][i]);
    }
    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {

            if (up_key[i] == up_key[j])
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }
    int i = 0;
    plaintext = get_string("plaintext:");
    output = plaintext;
    while (plaintext[i] != '\0')
    {
        if (plaintext[i] >= 65 && plaintext[i] <= 90)
        {
            output[i] = up_key[plaintext[i] - 65];
        }
        else if (plaintext[i] >= 97 && plaintext[i] <= 122)
        {
            output[i] = down_key[plaintext[i] - 97];
        }
        else
        {
            output[i] = plaintext[i];
        }
        i++;
    }
    printf("ciphertext:%s\n", output);
    return 0 ;
}

