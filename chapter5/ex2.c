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


int getfloat(float *pn)
{
	int sign, character;
	
	float fractional = 1;

	while(isspace(character = getch())); //get input until we get a non-space character
	
	if(!isdigit(character) && character != '+' && character != '-' && character != EOF)
	{
		ungetch(character);
		return -1;
	}

	sign = (character == '-') ? -1 : 1;

	
	if(character == '+' || character == '-')
		character = getch();

	for(*pn = 0; isdigit(character); character = getch())
		*pn = 10 * *pn + (character - '0');    //for integer part
	
	if(character == '.')
		character = getch();
	
	for(; isdigit(character); character = getch())
	{
		*pn = 10 * *pn + (character - '0');    //for fractional part
		fractional *= 10.0;
	}
	
	
		
	*pn *= sign;
	*pn /= fractional;
	

	if(character != EOF)
		ungetch(character);

	return character;
}

void main()
{
	int i, count;
	float array[SIZE];

	for(i = 0; i < SIZE && getfloat(&array[i]) != EOF; i++)
		count++;
	
	for(i = 0; i < count; i++)
		printf("ELEMENT AT INDEX %d : %f\n", i, array[i]);
	
	
}





