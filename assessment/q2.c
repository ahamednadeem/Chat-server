//print prime numbers between 1 and 300

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int flag = 0;
	int lower = 2;
	int upper = 300;
	printf("%d\n", 2);

	for(int i = lower + 1; i < upper + 1; i++)
	{
		for(int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				flag = 1 ;
				break;
			}
		}
		if(flag == 0)
			printf("%d\n", i);
	
		else
			flag = 0;	
	}
}

			

