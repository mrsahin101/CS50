// Implements a dictionary's functionality
#include <cs50.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>

#include "dictionary.h"

int dict_size = 0 ;
bool dict_status = false;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 27;

// Hash table
node *table[(N * N * N) + N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int index = 0;
    index = hash(word);
    for (node *cursor = table[index]; cursor != NULL; cursor = cursor->next)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
    }
    return false;

}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    char temp_word[LENGTH + 1];
    for (int i = 0, j = strlen(word); i <= j; i++)
    {
        temp_word[i] = tolower(word[i]);
    }
    if (strlen(temp_word) >= 3)
    {
        return ((temp_word[0] - 96) * N * N) + ((temp_word[1] - 96) * N) + (temp_word[2] - 96);
    }
    else
    {
        return N * N * N + (temp_word[0] - 96);
    }
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    for (int i = 0; i < ((N * N * N) + N); i++)
    {
        table[i] = NULL;
    }
    node *n = NULL;
    char buffer[50];
    unsigned int index = 0;
    char buffer_word[LENGTH + 1];
    sprintf(buffer, "./%s", dictionary);
    FILE *dict = fopen(buffer, "r");
    if (dict == NULL)
    {
        return false;
    }
    while (fscanf(dict, "%s", buffer_word) != EOF)
    {
        n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        strcpy(n->word, buffer_word);
        index = hash(buffer_word);
        n->next = table[index];
        table[index] = n;
        dict_size++;
    }
    /*FILE* output = fopen("deneme3.txt","w");
    for (int i = 0 ; i < 19710; i++)
    {
        fprintf(output,"%i-,",i);
        for(node* isaret = table[i]; isaret != NULL; isaret = isaret->next)
        {
        fprintf(output,"%s,",isaret->word);
        }
        fprintf(output,"\n");
    }
    fclose(output);*/
    fclose(dict);
    dict_status = true;
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (dict_status == true)
    {
        return dict_size;
    }
    else
    {
        return 0;
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *temporary = NULL;
    for (int i = 0; i < ((N * N * N) + N); i++)
    {
        while (table[i] != NULL)
        {
            temporary = table[i]->next;
            free(table[i]);
            table[i] = temporary;
        }
    }
    return true;
}
