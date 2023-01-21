// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Declare variables
unsigned int word_count;
unsigned int hash_index;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash word to obtain a hash value
    hash_index = hash(word);

    // Set to first item in linked list
    node *cursor = table[hash_index];

    // Iterate in each item of linked list
    while (cursor != 0) // NULL
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // Create a variable for total of the chars
    unsigned long total = 0;
    // Iterate each char in word
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        total += toupper(word[i]);
    }
    // Return what bucket that the word belongs to
    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *file = fopen(dictionary, "r");
    // check the file, if is NULL
    if (file == NULL)
    {
        printf("%s is not eable for open", dictionary);
        return false;
    }

    // Declared variable
    char word[LENGTH + 1];

    // Read strings from file one at a time
    // fscanf will return EOF is end of file
    while (fscanf(file, "%s", word) != EOF)
    {
        // Allocate memory for new node
        node *n = malloc(sizeof(node));
        // check if n is NULL
        if (n == NULL)
        {
            return false;
        }
        // Create a new node for each word
        // Copy word into node
        strcpy(n->word, word);
        // Hash word to obtain a hash value
        hash_index = hash(word);
        // Insert node into hash table at that location
        n->next = table[hash_index];
        table[hash_index] = n;
        word_count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // Return number of words
    // Take the sum of words in function load (word_count++)
    if (word_count > 0)
    {
        return word_count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Iterate through buckets
    for (int i = 0; i < N; i++)
    {
        // Set to first item in linked list
        node *cursor = table[i];

        // if cursor is not NULL, free
        while (cursor != NULL)
        {
            // Copy of pointer of linked list
            node *tmp = cursor;

            // Move cursor to next node
            cursor = cursor->next;
            // Free up the memory
            free(tmp);
        }
        // if cursor is NULL and i == N - 1
        if (cursor == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
