/* Swap two Numbers using Bitwise Operators */

#include<stdio.h>

int main()
{
	int num1 = 13;
	int num2 = 54;
	
	printf("Before swapping\n");
	printf("num1: %d num2: %d \n", num1, num2);
	
	
	int temp = num1 & (-1);
	num1 = num2 & (-1);
	num2 = temp & (-1);
	
	printf("After swapping\n");
	printf("num1: %d num2: %d \n", num1, num2);
	
	return 0;
}
	
	
	
	
