#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Please allocate a file to open\n");
    }

    char *dictionary = argv[1];
    FILE* fd = fopen(dictionary, "r");

    if (!fd)
    {
        printf("Could not load %s.\n", dictionary);
        return 1;
    }

    printf("character[1]: %c\n", fgetc(fd));
    printf("character[2]: %c\n", fgetc(fd));
    printf("character[3]: %c\n", fgetc(fd));

}