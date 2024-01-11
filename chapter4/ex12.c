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

void itoa(int number, char s[])
{
	static int i = 0;
	if (number < 0)
	{
		number *= -1;
		s[i++] = '-';
	}
	
	if(number / 10)
	{
		itoa(number / 10, s);
	}
	
	s[i++] = number % 10 + '0';
	s[i] = '\0';
}

	
	
	
	
