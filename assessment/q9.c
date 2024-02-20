/* For a given positive integer K of not more than 1000000 digits, write the value of the smallest palindrome larger than K to output. */

#include<stdio.h>

int main()
{
	int k = 124122; // we are finding plaindrome number above this value (k)
	int num = k + 1;
	
	
	while(1)
	{
		int sum = 0;
		int copy = num;
		int res;
		
		while(copy)
		{
			res = copy % 10;
			sum = sum * 10 + res;
			copy /= 10;
		}
		
		if (sum == num)
		{
			printf("Palindrome found: %d", num);
			break;
		}
		else
			num++;
	}
	
	return 0;
}
			
			
			

