#include <stdio.h>
#define MAXLINE 1000

int mgetline(char line[], int lim);

void squeeze(char line1[], char line2[], char line3[]);

int main() 
{
    char line1[MAXLINE], line2[MAXLINE], line3[MAXLINE];
    mgetline(line1, MAXLINE);
    mgetline(line2, MAXLINE);
    squeeze(line1, line2, line3);
    printf("%s", line3);
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

void squeeze(char line1[], char line2[], char line3[]) 
{
    int i, j, k;
    k = 0;
    for (i = 0; line1[i] != '\0'; ++i) 
    {
    	int flag = 0;
    	
        for (j = 0; line2[j] != '\0'; ++j)
        {
        	if(line1[i] == line2[j])
        	{
        		flag = 1;
        		break;
        	}
        }
        if (!flag)
        {
        	line3[k] = line1[i];
        	k++;
        }
    
        
    }
    line3[k] = '\0';
}
