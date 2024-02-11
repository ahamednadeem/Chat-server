/* As written, getint treats a + or - not followed by a digit as a valid
representation of zero. Fix it to push such a character back on the input. */


#include<stdio.h>
#include<ctype.h>

#define SIZE 100
#define BUFSIZE 100

char buf[BUFSIZE];
int buffer_pointer = 0;
int flag = 0;

int getch(void)  // get input from the buffer or from getchar() function
{
	return (buffer_pointer > 0) ? buf[--buffer_pointer] : getchar();
}

void ungetch(int character)  // store the data in the buffer 
{
	if(buffer_pointer >= BUFSIZE)
		printf("too many character\n");
	else
		buf[buffer_pointer++] = character;
}


int getint(int *pn)  // get input from the user using pointer variables
{
	int character, sign;

	while(isspace(character = getch())); //get input until we get a non-space character
	
	if(!isdigit(character) && character != '+' && character != '-' && character != EOF)
	{
		ungetch(character);
		return -1;
	}

	sign = (character == '-') ? -1 : 1;  // note down the sign 

	
	if(character == '+' || character == '-')
		character = getch();
		
	if(!isdigit(character)) //to make sure the character after '+' or '-' is a digit
	{
		flag = 1;
		return character;
	}

	for(*pn = 0; isdigit(character); character = getch())   // converting into integer values
		*pn = 10 * *pn + (character - '0');

	*pn *= sign;

	if(character != EOF)
		ungetch(character);

	return character;
}

void main()
{
	int i, array[SIZE], count = 0;

	for(i = 0; i < SIZE && (getint(&array[i])) != EOF; i++)
	{
	
		if(flag)  // if a digit is not followed by '-' or '+'
		{
			printf("Invalid input at index %d\n", i);
			break;
		}
	count++;
        }
        
	for(i = 0; i < count; i++)
		printf("index %d : %d \n", i, array[i]);		
}
