#include <stdio.h>
#include<stdlib.h>

#define MAXLINE 1000

int _getline(char line[], int lim);
int remove_trail(char rline[]);

int main(void) 
{
    int len;
    char line[MAXLINE];
    
    while ((len = _getline(line, MAXLINE)) > 0)
        if (remove_trail(line) > 0)
            printf("%s\n", line);
            
    return 0;
}

int _getline(char line[], int lim) 
{
    int i, character;
    for (i = 0; (character = getchar()) != EOF && character != '\n'; ++i)
    {
    	if (i < lim - 1)
    		line[i] = character;
    	else
    	{
    		printf("Word Limit Exceeded");
    		exit(0);
    	}
    }
        
    if (character == '\n') 
        line[i++] = character;
        
    line[i] = '\0';
    
    return i;

}

// To remove Trailing Blanks,tabs. Go to End and proceed backwards removing
int remove_trail(char rline[]) 
{
    int i;

    for (i = 0; rline[i] != '\n'; ++i);  //we traverse to \n
    --i;                                                        
    for (i > 0; ((rline[i] == ' ') || (rline[i] == '\t')); --i); 
    if (i >= 0)                                                 
    {
        ++i;
        rline[i++] = '*';   //to mark the ending of the word   (for viewing purpose)
        rline[i++] = '\n';
        
        rline[i] = '\0';
    }
    return i;
}
