/* pointer version of the function strcat */

#include<stdio.h>
#define SIZE 1000
#define MAXLINE 1000

void mgetline(char line[], int lim);
void mstrcat(char *, char *);

void main()
{
	char s[SIZE];
	char t[SIZE];
	
	mgetline(s, MAXLINE);  // get input line for s
	mgetline(t, MAXLINE);  // get input line for t
	
	mstrcat(s, t);
	printf("%s\n", s);
}


void mgetline(char line[], int lim)   // get input line from the user
{
	int character, i;
	for(i = 0; i < lim -1 && (character = getchar()) != EOF && character != '\n';i++)
		line[i] = character;
	
	line[i] = '\0';
}

	
void mstrcat(char *s, char *t)  // concatenates string t to s
{
	while(*s != '\0')  // goes to the end of string s
		s++;
	while((*s++ = *t++) != '\0');  // copy contents of t in s
}
		
	
	
	



