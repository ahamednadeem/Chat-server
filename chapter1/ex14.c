#include<stdio.h>

#define maximum 128

void main()
{
	int c;
	int characters[maximum];
	for(int i = 0; i < maximum; i++)
		characters[i] = 0;
		
		
	while((c = getchar()) != EOF)
		characters[c] += 1;
	for(int i = 0; i < maximum; i++)
	{
		putchar(i);
	
		for(int j = 0; j < characters[i]; j++)
			printf(" *");
		
		printf("\n");
	}
}

