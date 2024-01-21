/* a function reverse(s) that reverses the character string s */

#include<stdio.h>
#include<stdlib.h>

#define MAXLINE 10

int getlines(char line[], int lim);
void reverse_string(char rev[]);

int main() 
{
    int len;
    char line[MAXLINE];

    while ((len = getlines(line, MAXLINE)) > 0)
    {		reverse_string(line);
       	printf("%s", line);
    }

    return 0;
}

int getlines(char line[], int lim)     //get input from the user
{
    int i, character;
    for (i = 0; (character = getchar()) != EOF && character != '\n'; ++i)
    {
    	if (i < lim - 1)
    		line[i] = character;
    	else
    	{
    		line[i] = character;
    		printf("Word Limit Exceeded\n");
    		reverse_string(line);
       	printf("%s", line);
    		exit(0);
    	}
    }
        
    if (character == '\n') 
        line[i++] = character;
        
    line[i] = '\0';
    
    return i;

}

 
void reverse_string(char rev[])    // revrerses the input line
{
    int i, j;
    char temp;

    for (i = 0; rev[i] != '\0'; ++i);
    	--i;

    if (rev[i] == '\n')
        --i;

    j = 0;

    while (j <= i) 
    {
        temp = rev[j];
        rev[j] = rev[i];
        rev[i] = temp;
        --i;
        ++j;
    }
}
	
	
