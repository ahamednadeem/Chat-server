/* Modify the temperature conversion program to print a heading above the table */

#include<stdio.h>

void main()
{
	float farh, celcius;
	int low = 0, high = 300, step = 20; 
	
	farh = low;
	printf("Farhenheit to Celcius Conversion table : \n");  //Heading above the table
	
	while(farh <= high)
	{
		celcius = (5.0 / 9.0) * (farh - 32.0);
		printf("%4.0f %10.1f\n", farh, celcius);
		farh += step;
	}
}
