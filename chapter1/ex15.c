/*Rewrite the temperature conversion program of Section 1.2 to use a function
for conversion.*/

#include<stdio.h>

//celcius to farhenheit
float celcius_to_farhenheit(float celc)
{
	float farh = (9.0/5.0) * celc + 32;
	return farh;
}

//farhenheit to celcius
float farhenheit_to_celcius(float farh)
{
	float celc = (farh - 32) * (5.0/9.0);
	return celc;
}


void main()
{
	float farh, celcius;
	int lower = 0;
	int upper = 300;
	int size = 20;


	printf("celcius to farhenheit\n\n");
	celcius = upper;
	while(celcius >= lower)
	{
		printf("%3.0f %15.1f\n", celcius, celcius_to_farhenheit(celcius));
		celcius -= size;
	}
	
	printf("farhenheit to celcius\n\n");
	farh = lower;
	while(farh <= upper)
	{
		printf("%3.0f %15.1f\n", farh, farhenheit_to_celcius(farh));
		farh += size;
	}
}

	
