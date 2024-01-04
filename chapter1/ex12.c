#include<stdio.h>
/*void main()
{
	int c;
	while((c = getchar()) != EOF)
	{
		if (c == ' ')
		{
			printf("\n");
		}
		
		else 
		{
			putchar(c);
		}
	}
}
*/

void main()
{
	int c;
	int in = 0;
	int out = 1;
	int state = out;
	while((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\n' || c == '\t')
		{
			if (state == in)
			{
				printf("\n");
				state = out;
			}
		}
		else if (state == out)
		{
			putchar(c);
			state = in;
		}
		
		else
		{
			putchar(c);
		}
	}
}

				
				
