#include<stdio.h>

void main()
{
	int maxword = 11;
	int in = 1;
	int out = 0;

	int c, i, nc, state;
	state = out;
	int maxvalue;
	int wl[maxword];
	
	nc = 0;

	for(i = 0; i < maxword; i++)
	{
		wl[i] = 0;
	}

	while((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\n' || c == '\t')
		{
			state = out;
			
			if (nc > 0)
				wl[nc]++;
				
			nc = 0;

		}

		else if(state == out)
			{
				state = in;
				nc = 1;
			}
		else
			nc++;
	}

	maxvalue = 0;
	for (i = 0; i < maxword; i++)
	{
		if (wl[i] > maxvalue)
		{
			maxvalue = wl[i];
		}
	}

	for(i = 1; i < maxword; i++)
	{
		printf("%3d - %3d", i, wl[i]);
	}
}



	
	
