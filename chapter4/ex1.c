/*bfunction strindex(s,t) which returns the position of the rightmost
occurrence of t in s , or -1 if there is none */


#include<stdio.h>
#include<string.h>
#define MAXLINE 1000  //This gives the limit for maximum lines

int strindex(char s[], char t[]); 
void getlines(char s[], int lim);

void main()
{
	char s[MAXLINE];      //we get s as input from the user
	char t[] = "opi";     //sample text

	int c;
	getlines(s, MAXLINE); 
	
	int res = strindex(s, t);
	if (res >= 0)
	{
		printf("Element Found at pos %d \n", res + 1);
	}
	else
	{
		printf("Element not found \n ");
	}
}

void getlines(char s[], int lim) //get input from the user character by character and store it in character array
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

int strindex(char s[],char t[])  //finds the rightmost occurance of t in s
{
    int i, j, k, result;
    result = -1;
    
    for(i = 0; s[i] != '\0'; i++)
    {
        for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);
        
        if(t[k] == '\0')  
            result = i; //we keep updating this to find the rightmost index
    }
    return result;
}

