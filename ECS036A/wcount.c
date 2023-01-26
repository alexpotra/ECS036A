#include <stdio.h>
#include <ctype.h>

// gets the word count from a file
int wordCount(FILE *file)
{
    int wCount = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF)
    {
        if (isspace(ch))
        {
            while (isspace(ch = fgetc(file)))
            {
            }
            wCount++;
        }
    }
    return wCount;
}

int main(int argc, char *argv[])
{
    // set up input file
    FILE *inputFile = fopen(argv[1], "r");

    // print output using wordCounts
    printf("There are %d word(s).", wordCount(inputFile));
    return 0;
}