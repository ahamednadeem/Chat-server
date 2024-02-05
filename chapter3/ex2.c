/* function escape(s,t) that converts characters like newline and tab into
visible escape sequences like \n and \t as it copies the string t to s */

#include<stdio.h>
#include<stdlib.h>

#define MAXLINE 10

void mgetline(char s[], int maxline);
void escape(char s[], char t[]);


void main()
{
	char s[MAXLINE], t[MAXLINE];
	mgetline(t, MAXLINE);
	escape(s, t);
	printf("%s", s);
}

void mgetline(char t[], int lim)  //get input line from the user
{
    int i, character;

    for (i = 0; i < lim  && (character = getchar()) != EOF; ++i)
        t[i] = character;
        
    t[i] = '\0';
}

void escape(char s[], char t[])  //convertes newline and tabs into visible characters
{
	int i = 0, j = 0;
	while (t[i] != '\0') 
	{
        	switch (t[i]) 
		{
        		case '\t':
            		s[j] = '\\';
            		j++;
            		s[j] = 't';
			break;
        		
			case '\n':
            		s[j] = '\\';
            		j++;
            		s[j] = 'n';
			break;
        
			default:
            		s[j] = t[i];  
            		break;
        	}
        	++i;
        	++j;
    	}

    	s[j] = '\0';
}
	
