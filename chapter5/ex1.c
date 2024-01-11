#include<stdio.h>
#include<ctype.h>

#define SIZE 100
#define BUFSIZE 100

char buf[BUFSIZE];
int buffer_pointer = 0;


int getch(void)
{
	return (buffer_pointer > 0) ? buf[--buffer_pointer] : getchar();
}

void ungetch(int character)
{
	if(buffer_pointer >= BUFSIZE)
		printf("too many character\n");
	else
		buf[buffer_pointer++] = character;
}


int getint(int *pn)
{
	int character, sign;

	while(isspace(character = getch())); //get input until we get a non-space character
	
	if(!isdigit(character) && character != '+' && character != '-')
	{
		ungetch(character);
		return -1;
	}

	sign = (character == '-') ? -1 : 1;

	
	if(character == '+' || character == '-')
		character = getch();
		
	if(!isdigit(character)) //to make sure the character after '+' or '-' is a digit
		return 0;

	for(*pn = 0; isdigit(character); character = getch())
		*pn = 10 * *pn + (character - '0');
	*pn *= sign;

	if(character != EOF)
		ungetch(character);

	return character;
}

void main()
{
	int i, s, array[SIZE];

	for(i = 0; i < SIZE && getint(&array[i]) != EOF; i++)
		printf("In array index %d : %d\n", i, array[i]);
	
}





