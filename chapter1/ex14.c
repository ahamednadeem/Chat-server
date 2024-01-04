#include<stdio.h>
#include<ctype.h>

#define MAXHIST 15
#define MAXCHAR 128

void main()
{
	int c, i;
	int len;
	int maxvalue = 0;
	int cc[MAXCHAR];

	for (i = 0; i < MAXCHAR; i++)
	{
		cc[i] = 0;
	}
	
	while((c = getchar()) != EOF)
	{
		if (c < MAXCHAR)
			++ cc[c];
	}
	
	
	for(i = 1; i < MAXCHAR; ++i)
	{
		if ( cc[i] > maxvalue)
		{
			maxvalue = cc[i];
		}
	}
	
	for(i = 1; i < MAXCHAR; i++)
	{
		printf("%5d - %5d", i, cc[i]);
		
		if (cc[i] > 0)
		{
			if ((len - cc[i] * MAXHIST / maxvalue) <= 0)
				len = 1;
		}
		else
		{
			len = 0;
		}
		for (i = 0; i < len; i++)
		{
			printf("*");
		}
		printf("\n");
	}
}
		
