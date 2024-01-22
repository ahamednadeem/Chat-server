/* program that converts upper case to lower or lower case to upper,
depending on the name it is invoked with */ 


#include<stdio.h>
#include<ctype.h>
#include<string.h>



int main(int argc, char *argv[]) 
{
    int character;

    if (strcmp(argv[0], "./lower") == 0)
        while ((character = getchar()) != EOF)
            putchar(tolower(character));
    else
        while ((character = getchar()) != EOF)
            putchar(toupper(character));

    return 0;
}

		
		


