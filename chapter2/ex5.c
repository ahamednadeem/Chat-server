/* function any(s1,s2) , which returns the first location in a string s1
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2 . */


#include <stdio.h>
#include<stdlib.h>

#define MAXLINE 1000

void mgetline(char line[], int lim);
int any(char line1[], char line2[]);

int main() 
{
    int res;
    char line1[MAXLINE], line2[MAXLINE];
    mgetline(line1, MAXLINE);
    mgetline(line2, MAXLINE);
    res = any(line1, line2);
    printf("%d\n", res);
    	
    return 0;
}

void mgetline(char s[], int lim)  //get input from the user
{
    int i, character;
    for (i = 0; i < lim && (character = getchar()) != EOF && character != '\n'; ++i)
        s[i] = character;
    
    if(i >= lim)
    {
    	printf("Line limit Exceeded \n");
    	exit(0);
    }

  
    s[i] = '\0';
}

int any(char line1[], char line2[]) //returns the first location in a string s1 where any character from the string s2 occurs
{
    int i, j, flag = 0;

    for (j = 0; line2[j] != '\0'; ++j) 
    {
        for (i = 0; line1[i] != '\0'; ++i)
        {
        	if(line1[i] == line2[j])
        	{
        		return i + 1;
        	}
        }
        
  
        
    }
    return -1;
  
}
    
