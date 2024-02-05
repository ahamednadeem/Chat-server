/* converts upper case letters to lower case,
with a conditional expression instead of if-else . */


#include <stdio.h>

int lower(int c);

int main(void) 
{
	int character;

    	while ((character = getchar()) != EOF) 
		putchar(lower(character));
}

int lower(int c)  {
	return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;  //used ternary operator 
}
