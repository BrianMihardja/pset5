// Implements a dictionary's functionality

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "dictionary.h"

#define LENGTH 45

typedef struct node
{
    bool is_word;
    struct node *children[27];
}
node;

void emptynodes(node *firstnode)
{
    for(int i = 0; i < 27; i++)
    {
        if(firstnode -> children[i] != NULL)
        {
            emptynodes(firstnode -> children[i]);
        }
    }
    free(firstnode);
    return;
}

//sets global nodes.
node *firstnode; //sets a first node to be the starting point of all load and check.
node *children[27]; //sets the children node array to 27 (26 alphabets + '\'')
node *cursornode = NULL;     //make another node as a cursor/pointer
                            //to know which node we are currently at.
node *checknode;

int total_words = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int intA = (int)'a';
    int checkCharInt = 0; //used to find the Int value of each char in word to be checked.

    checknode = firstnode;

    //checking whether the word is in the dictionary
    for (int i = 0; i < strlen(word); i++)
    {
        checkCharInt = tolower(word[i]) - intA;
        if(checkCharInt == -58)
        {
            checkCharInt = 26;
        }

        //checking if the node is already loaded by the dictionary.
        if(checknode -> children[checkCharInt] != NULL)
        {
            checknode = checknode -> children[checkCharInt];
        }
        else
        {
            return false;
        }
    }

    if(checknode -> is_word == true)
    {
        return true;
    }
    else
    {
        return false;
    }

    printf("word is %s\n", word);

    return false;
}


// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //opens dictionary file position argv[1] for reading
    FILE* fd = fopen(dictionary, "r");

    if (!fd)
    {
        printf("Could not load %s.\n", dictionary);
        return 1;
    }

    firstnode = (node*)malloc(sizeof(node)); //sets a memory for firstnode.
    int intA = (int)'a'; //intA == 97 as per ASCII.
    // printf("intA = %i\n", intA);
    int characterInt = 0;

    while((characterInt = fgetc(fd)) != EOF)
    {
        cursornode = firstnode; //set the cursor into the firstnode at the start of every word.
        while(characterInt == 39 || (characterInt >= 97 && characterInt <= 122)) //loop runs as long as it isn't end of word.
        {
            // printf("current letter: %c\n", characterInt);
            if(characterInt == '\'')
            {
                characterInt = intA + 26;
            }
            //check if node is empty, and make a node if it is empty.
            if(cursornode -> children[characterInt - intA] == NULL) //pointing to the address of children[characterInt]
            {
                cursornode -> children[characterInt - intA] = (node*)malloc(sizeof(node));
                cursornode = cursornode -> children[characterInt - intA];
            }
            else //move to the node address if it is already made.
            {
                cursornode = cursornode -> children[characterInt - intA];
            }

            characterInt = fgetc(fd); //gets the next character.
        }
        //if end of word is found '\n'

        total_words++;
        // printf("total words: %i\n", total_words);
        cursornode -> is_word = true;
    }

    // cursornode = firstnode -> children[2];
    // cursornode = cursornode -> children[0];
    // if(cursornode -> children[19] == NULL)
    // {
    //     printf("load failed\n");
    // }

    fclose(fd);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return total_words;
}




// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    node *clearingnode1 = firstnode;
    emptynodes(clearingnode1);

    return true;
}
