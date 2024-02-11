/* printd to write a recursive version of itoa ; that is, convert
an integer into a string by calling a recursive routine. */


#include<stdio.h>
#define MAXI 100

void itoa(int number, char s[]);

void main()
{
	int number = -1232;
	char s[MAXI];
	
	itoa(number, s);
	printf("%s", s);
	
}

void itoa(int number, char s[])  // converts integer to string
{
	static int i = 0;
	if (number < 0)
	{
		number *= -1;
		s[i++] = '-';
	}
	
	if(number / 10)
	{
		itoa(number / 10, s); // revursive call 
	}
	
	s[i++] = number % 10 + '0';  // now we convert it to string recursively, at each iteration the value of number is different
	s[i] = '\0';
}

	
	
	
	
