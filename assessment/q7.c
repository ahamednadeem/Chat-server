/* 45*45=2025; 20+25=45.Write a program to generate number between 32 and 99 that satisfies the above property. */

#include<stdio.h>
#include<math.h>

int main()
{
	int x, first, last;
	
	int j;
	for(j = 32; j <= 99; j++)
	{
		int result = pow(j, 2);
		int res = result;
		int y = 0;
		//printf("result: %d\n", result);
		
		result /= 10;
		last = result / 10;  // this contains the first 2 numbers
		//printf("j : %d\n", j);
		
		
		//printf("last: %d\n", last);
		
		
		for(int j = 0; j < 2; j++)
		{
			x = res % 10;
			y = y * 10 + x;
			res /= 10;
		}
		
		int a, b = 0;
		
		for(int k = 0; k < 2; k++)
		{
			a = y % 10;
			b = b * 10 + a;  // this contains the last 2 numbers
			y /= 10;
		}
		first = b;
		
		//printf("first: %d\n", first);
		
		if((first + last ) == j)
		{
			printf("%d\n", j);
		}
	}
	return 0;
}
		
		
			
			 
			
			

