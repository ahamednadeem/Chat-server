/* Write a program to compare two files, printing the first line where they differ. */




#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX_LINE_LENGTH 100

void file_compare(FILE *file1, FILE *file2);

int main(int argc, char *argv[]) 
{
    FILE *file1, *file2; //pointers for file1 and file2

    if (argc == 1) //no input in command line
    {
        printf("Please provide two files as arguments to proceed ");
        return 1;
    } 
    else
        {
            if((file1 = fopen(argv[1], "r")) == NULL)
		{
			printf("Can't open file %s\n", argv[1]);  //if wrong file name is given or file name does not exist
			return 1;
		}
		if((file2 = fopen(argv[2], "r")) == NULL)
		{
			printf("Can't open file %s\n", argv[2]);  //if wrong file name is given or file name does not exist
			return 1;
		}
	}

	file_compare(file1, file2);
	fclose(file1);
	fclose(file2);
   

    return 0;
}

void file_compare(FILE *file1, FILE *file2) 
{
    char line1[MAX_LINE_LENGTH], line2[MAX_LINE_LENGTH];
    int lineNum = 1;

    while (fgets(line1, MAX_LINE_LENGTH, file1) != NULL && fgets(line2, MAX_LINE_LENGTH, file2) != NULL) 
    {
        if (strcmp(line1, line2) != 0) 
        {
        	
            printf("Files differ at line %d:\n", lineNum);
            printf("file 1: %s", line1);
            printf("file 2: %s", line2);
            
            return;
        }

        lineNum++;
    }
    
    if (fgets(line1, MAX_LINE_LENGTH, file1) != NULL) 
    {
        printf("Files differ at line %d :\n", lineNum);
        printf("%s", line1);
    } 
    else if (fgets(line2, MAX_LINE_LENGTH, file2) != NULL) 
    {
        printf("Files differ at line %d:\n", lineNum);
        printf("%s", line2);
    } 
    else 
    {
        printf("Files are identical.\n");
    }
    
    
    
}


