#include<stdio.h>


void mgetline(char s[], int maxline);
void escape(char s[], char t[]);

void main()
{
	int maxline = 1000;
	char s[maxline], t[maxline];
	mgetline(t, maxline);
	escape(s, t);
	printf("%s", s);
}



void mgetline(char t[], int lim) 
{
    int i, character;

    for (i = 0; i < lim - 1 && (character = getchar()) != EOF; ++i)
        t[i] = character;

    t[i] = '\0';
}



void escape(char s[], char t[])
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
	
