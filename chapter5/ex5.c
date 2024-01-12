#include<stdio.h>
#define SIZE 100
#define MAXLINE 100

void mgetline(char line[], int lim);
void mstrncat(char *, char *, int);
void mstrncpy(char *, char *, int);
int mstrncmp(char *, char *, int);


void main()
{
	char s[SIZE];
	char t[SIZE];
	
	
	int n = 5;
	
	
	mgetline(s, MAXLINE);
	mgetline(t, MAXLINE);
	
	mstrncat(s, t, n);
	printf("Concatenated : %s\n", s);
	
	n = 6;
	
	mstrncpy(s, t, n);

	
	
	printf("%s\n", s);
	char s1[SIZE];
	char s2[SIZE];
	
	mgetline(s1, MAXLINE);
	mgetline(s2, MAXLINE);
	
	n = 4;
	if(mstrncmp(s1, s2, n))	
		printf("Same till %d characters\n", n);
	else
		printf("Not same\n");
	
}


void mgetline(char line[], int lim)
{
	int character, i;
	for(i = 0; i < lim -1 && (character = getchar()) != EOF && character != '\n';i++)
		line[i] = character;
	
	line[i] = '\0';
}

	
void mstrncat(char *s, char *t, int n)
{
	if (n > 0)
	{	
		int count = 0;
		while(*s != '\0')
		s++;
		while((*s++ = *t++) != '\0' && (++count < n-1));
	}
}

void mstrncpy(char *s, char *t, int n)
{
	//printf("In strcpy\n");
	char *p = s;
	if (n > 0)
	{
		int count = 0;
		while(*s++ = *t++ && (++count < n));	
	}
	printf("Copied %s\n", s);
}

int mstrncmp(char *s1, char *s2, int n)
{	
	int count = 0;
	
	while(*s1++ == *s2++ && *s1 != '\0' && *s2 != '\0')
		count++;
	if(count >= n)
		return 1;
	
	return 0;
}
	
	
	
		
	
	
	



