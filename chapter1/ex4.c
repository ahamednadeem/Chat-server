/*Write a program to print the corresponding Celsius to Fahrenheit table. */


#include<stdio.h>
void main()
{
	float celcius, farh;
	int lower = 0;
	int upper = 300;  
	int size = 20;

	celcius = lower;
	while(celcius <= upper)  
	{
		farh = (9 * celcius / 5) + 32;    //celcius is converted to farhenheit
		printf("%3.0f %6.1f\n", celcius, farh);
		celcius += size;
	}
}

