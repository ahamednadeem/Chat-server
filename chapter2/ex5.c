#include <stdio.h>
#define MAXLINE 1000

int mgetline(char line[], int lim);
int any(char line1[], char line2[]);

int main() 
{
    int res;
    char line1[MAXLINE], line2[MAXLINE];
    mgetline(line1, MAXLINE);
    mgetline(line2, MAXLINE);
    res = any(line1, line2);
    printf("%d", res);
    	
    return 0;
}

int mgetline(char s[], int lim) 
{
    int i, character;
    for (i = 0; i < lim - 1 && (character = getchar()) != EOF && character != '\n'; ++i)
    {
        s[i] = character;
    }
    if (character == '\n')
    {
        s[i++] = character;
    }
    s[i] = '\0';
}

int any(char line1[], char line2[]) 
{
    int i, j;
    for (j = 0; line2[j] != '\0'; ++j) 
    {
        for (i = 0; line1[i] != '\0'; ++i)
        {
        	if(line1[i] == line2[j])
        	{
        		return i+1;
        	}
        }
        
    
        
    }
    return -1;
  
}
    
