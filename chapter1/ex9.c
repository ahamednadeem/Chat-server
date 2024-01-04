#include<stdio.h>
void main()
{
	int c, prev;
	prev = '0';
	while((c = getchar()) != EOF)
	{
		if (c != ' ')
		{
			putchar(c);
		}

		else if (prev != ' ')
		{
			putchar(c);
		}

		prev = c;
		printf("\n");
	}
}

