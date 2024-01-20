/* program to copy its input to its output, replacing each string of one or
more blanks by a single blank. */

#include<stdio.h>
void main()
{
	int c, prev;
	prev = '0';
	while((c = getchar()) != EOF)
	{
		if (c != ' ')
			putchar(c);

		else if (prev != ' ')
			putchar(c);
		prev = c;
	
	}
}

