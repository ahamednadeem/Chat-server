/* Write getfloat , the floating-point analog of getint */

#include<stdio.h>
#include<ctype.h>

#define SIZE 100
#define BUFSIZE 100

char buf[BUFSIZE];
int buffer_pointer = 0;


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


int getfloat(float *pn)   // get input as float data from the user and store it in the array using pointers
{
	int sign, character;
	float fractional = 1;

	while(isspace(character = getch())); //get input until we get a non-space character
	
	if(!isdigit(character) && character != '+' && character != '-' && character != EOF)
	{
		ungetch(character);
		return -1;
	}

	sign = (character == '-') ? -1 : 1;  // note down the sign	
	if(character == '+' || character == '-')
		character = getch();

	for(*pn = 0; isdigit(character); character = getch())
		*pn = 10 * *pn + (character - '0');    //for integer part, *pn is the value 
	
	if(character == '.')
		character = getch();
	
	for(; isdigit(character); character = getch())
	{
		*pn = 10 * *pn + (character - '0');    //for fractional part
		fractional *= 10.0;
	}
			
	*pn *= sign;
	*pn /= fractional;  // divide the total by fractional 
	

	if(character != EOF)
		ungetch(character);

	return character;
}

void main()
{
	int i, count;
	float array[SIZE];

	for(i = 0; i < SIZE && getfloat(&array[i]) != EOF; i++)  // to get inputs from the user
		count++;
	
	for(i = 0; i < count; i++)  // to print the elements in the array
		printf("ELEMENT AT INDEX %d : %f\n", i, array[i]);
	
	
}





