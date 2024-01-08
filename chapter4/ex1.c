#include<stdio.h>
#include<string.h>
#define MAXLINE 1000

int strindex(char s[], char t[]);
void getlines(char s[], int lim);

void main()
{
	char s[MAXLINE];
	char t[] = "xyz";

	int c;
	getlines(s, MAXLINE);
	
	int res = strindex(s, t);
	if (res >= 0)
	{
		printf("Found at pos %d \n", res + 1);
	}
	else
	{
		printf("Element not found \n ");
	}
}

void getlines(char s[], int lim) 
{
    int i, c;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
	    s[i] = c;
    }
    
    if (c == '\n')
    {		
        s[i++] = c;
    }

    s[i] = '\0';
}

int strindex(char s[],char t[])
{
    int i,j,k, result;
    result = -1;

    for(i = 0; s[i] != '\0'; i++)
    {
        for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if(k > 0 && t[k] == '\0')
            result = i; //we keep updating this to find the rightmost index
    }
    return result;
}

