/* unction strend(s,t) , which returns 1 if the string t occurs at the
end of the string s , and zero otherwise. */ 

#include<stdio.h>
#define SIZE 100
#define MAXLINE 100

void mgetline(char line[], int lim);
int mstrend(char *, char *);

void main()
{
	char s[SIZE], t[SIZE];
	
	mgetline(s, MAXLINE);
	mgetline(t, MAXLINE);
	
	printf("%d\n", mstrend(s, t));
}

void mgetline(char line[], int lim)   //get input from the user
{
	int character, i;
	for(i = 0; i < lim -1 && (character = getchar()) != EOF && character != '\n';i++)
		line[i] = character;
		
	if (character == '\n')
		line[i++] = character;
      
	
	line[i] = '\0';
}

int mstrend(char *s, char *t)   //to compute if t is at the end of s
{
	char *starting_s = s;	 //beginning address of s
	char *starting_t = t;    //beginning address of t
	
	for(; *s; s++); //going to the end of s
	for(; *t; t++); //going to the end of t
	
	for(; *s == *t; s--, t--)  // we check if they are same from the back
	{
		if(t == starting_t)  // required condition if t occurs at the back of s
			return 1;
	}
	return 0;
}

	
	
			
	
	
	
	
	
	
	



