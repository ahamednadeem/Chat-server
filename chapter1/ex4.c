#include<stdio.h>
int main()
{
	float farh, celcius;
	int lower = 0;
	int upper = 300;
	int size = 20;

	celcius = 0;
	while(celcius <= upper)
	{
		printf("%3.0f %6.1f\n", celcius, (9 * celcius / 5) + 32);
		celcius += size;
	}

	return 0;

}

