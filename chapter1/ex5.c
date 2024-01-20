/*Modify the temperature conversion program to print the table in reverse order,
that is, from 300 degrees to 0. */

#include<stdio.h>
void main()
{
	float farh, celcius;
	int lower = 0;
	int upper = 300;
	int size = 20;

	celcius = upper;   
	while(celcius >= lower)    // we print it in reverse order
	{
		printf("%3.0f %6.1f\n", celcius, (9 * celcius / 5) + 32);
		celcius -= size;
	}

}

