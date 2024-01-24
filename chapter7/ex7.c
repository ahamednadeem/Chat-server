#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000
int i;
void find_pattern(FILE *file, const char *pattern, int printFileName, char *file_name) 
{
    char line[MAXLINE];
    int lineNumber = 0;

    while (fgets(line, MAXLINE, file) != NULL) 
    {
        lineNumber++;
        if (strstr(line, pattern) != NULL)  //strstr is used to find pattern in the line, returns NULL is no patern is found
        {
            if (printFileName)   //we can print the file name if -p flag is given
                printf("%s: Found at linenumber: %d: line: %s",file_name, lineNumber, line);
            else 
                printf("Found at linenumber: %d: line: %s", lineNumber, line);
        }
    }
}

int main(int argc, char *argv[]) 
{                   
    if (argc < 2) 
    {
        printf("Invalid INput\n");
        return 1;
    }

    const char *pattern = argv[1];   //we give pattern in argv[1] 
    int printFileName = 0;    //want to print filename or not

    if (argc > 2 && strcmp(argv[2], "-p") == 0)   // Check if '-p' flag is provided to print the file name
        printFileName = 1;
    
    for (i = (printFileName ? 3 : 2); i < argc; i++) // Loop through the files provided as arguments or use standard input
    {
    	char *s = argv[i];
    	
        FILE *file = fopen(argv[i], "r");
        if (file == NULL) 
        {
            printf("Error!! File not found\n");
            continue;
        }
        find_pattern(file, pattern, printFileName, s);
        fclose(file);
    }

    
    if (argc == (printFileName ? 3 : 2))   // If no files provided, read from standard input
    {
    	char *p = "In stdin";
        find_pattern(stdin, pattern, printFileName, p);  
    }

    return 0;
}

