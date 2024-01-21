/* program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops */

#include<stdio.h>

#define TAB 8   // default tab space

int main() 
{
	int character, count = 0, space = 0;

	while((character = getchar()) != EOF) 
	{
	    if(character == '\t') 
	    {
		space = (TAB - (count % TAB));   //To maintain proper number of blanks
		while(space > 0)
		{
		    putchar(' ');
		    count++;
		    space--;
		}
	    }
	    else
	    {
		putchar(character);
		++count;
	    }

	    if(character == '\n')   //for a newline, we set count to 0
		count = 0;
	}	
	return 0;
}




