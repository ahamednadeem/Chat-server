/* `fold' long input lines into two or more shorter lines */

#include<stdio.h>

#define lim 10

void main()
{
	int character;
	int count = 0;
	
	while((character = getchar()) != EOF)
	{
		count++;
		if (count <= lim)	
			putchar(character);
		else
		{
			putchar('\n');
			count = 0;
		}
	}
}
		
			
