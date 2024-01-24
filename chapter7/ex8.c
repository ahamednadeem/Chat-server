#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINESPERPAGE 5
#define PAGELIMIT 30

void printpages(FILE *, FILE *);

int main(int argc, char *argv[]) 
{
    FILE *file_pointer;
    char *prog = argv[0];
    int linecount = 0;

    if (argc == 1) // No arguments give, get input from stdin 
    {
        printf("No files given, give input: \n");
        printpages(stdin, stdout);  // get input from the user(stdin) and print the output to the stdout
    } 
    else
        while (--argc > 0)
            if ((file_pointer = fopen(*++argv, "r")) == NULL) 
            {
                printf("can't open %s\n", prog);
                exit(0);
            } 
            else 
            {
                printf("File: %s\n", *argv);
                printpages(file_pointer, stdout);  //print the lines from given file to the stdout
                fclose(file_pointer);
            }

    return 0;
}

// copy file ifp to file ofp 
void printpages(FILE *ifp, FILE *ofp)   //ifp is the pointer to input file, ofp is pointer to output file
{
    int character;
    int line = 0;
    int page = 1;

    while ((character = getc(ifp)) != EOF && page <= PAGELIMIT ) 
    {
        putc(character, ofp);
        if (character == '\n')  //newline entered
        {
            line += 1;
            
            if (line == LINESPERPAGE) 
            {
                printf("\n\nEnd of page %d.\n\n", page);
                page += 1;
                line = 0;  //set line to 0 for a new page
            }
        }
    }
    
    if(page > PAGELIMIT)
    	printf("Page limit reached");
}
