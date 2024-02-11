/* recursive version of the function reverse(s) */

#include<stdio.h>

#define MAXLINE 100 //limit for length of string

void reverse(int i, int len, char s[]);
int mgetline(char line[], int lim);

void main()
{
	char s[MAXLINE];
	int len = mgetline(s, MAXLINE);
	printf("Before Reversed: %s", s);
	reverse(0, len, s);
	printf("Reversed : %s", s);
}


void reverse(int i, int len, char s[])  //reversing the string s by recursion
{
	int j, c;
	j = len - (i+1);  // As i increases, j decreases
	if(i < j)
	{
		c = s[j];
		s[j] = s[i];
		s[i] = c;
		reverse(++i, len, s); 
	}
	return ;
}


int mgetline(char line[], int lim) //getting input from the user
{
    int i, character;

    for (i = 0; i < lim - 1 && (character = getchar()) != EOF && character != '\n'; ++i)
        line[i] = character;

    if (character == '\n')
        line[i++] = '\n';

    line[i] = '\0';
    return i-1;
}
