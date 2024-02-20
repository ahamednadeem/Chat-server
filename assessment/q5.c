/* reverse a given number */

#include<stdio.h>

int main()
{
	int num;
	printf("Enter the number: ");
	scanf("%d", &num);
	
	int sum = 0;
	int r;
	
	while(num)
	{
		r = num % 10;
		sum = sum*10 + r;
		num /= 10;
	}
	
	printf("After reversing: ");
	
	printf("%d\n", sum);
}

