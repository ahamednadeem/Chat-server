#include<stdio.h>
#define SIZE 100
#define MAXLINE 100

void mgetline(char line[], int lim);
void mstrcat(char *, char *);

void main()
{
	char s[SIZE];
	char t[SIZE];
	
	
	mgetline(s, MAXLINE);
	
	mgetline(t, MAXLINE);
	
	mstrcat(s, t);
	printf("%s", s);
}


void mgetline(char line[], int lim)
{
	int character, i;
	for(i = 0; i < lim -1 && (character = getchar()) != EOF && character != '\n';i++)
		line[i] = character;
	
	line[i] = '\0';
}

	
void mstrcat(char *s, char *t)
{
	while(*s != '\0')
		s++;
	
	while((*s++ = *t++) != '\0');
}
		
	
	
	



