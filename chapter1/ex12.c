/* program that prints its input one word per line. */

#include<stdio.h>

void main()
{
	int c;
	int IN = 1;   //Inside the word
	int OUT = 0;  //Outside the word
	int state = OUT;
	while((c = getchar()) != EOF)
	{
		if(c == ' ' || c == '\n' || c == '\t')  
		{ 
			if(state == IN)   //checking is it is inside thw word
				{
					putchar('\n');
					state = OUT;
				}
		}
		else if(state == OUT)    //checking is it is outside thw word
		{
			 putchar(c);
			 state = IN;
		}
		else
			putchar(c);
	}
}

				
				

				
