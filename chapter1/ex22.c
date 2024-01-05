#include<stdio.h>

void main()
{
	int lim = 10;
	int character;
	int count = 0;
	
	
	while((character = getchar()) != EOF)
	{
		count++;
		if (count < lim)
		{	
			putchar(character);
		}
		else
		{
			putchar('\n');
			count = 0;
		}
	}
}
		
			
