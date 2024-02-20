/* Find the Biggest Number in an Array of Numbers using Recursion */

#include<stdio.h>
int printmax(int);

int maximum_number = -1;
int arr[5];

int main()
{
	printf("Enter Elements in the array: \n");
	for(int i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	printf("Maximum element in the array is: %d\n", printmax(5)); // we are passing the length of the array
	
	return 0;
}

int printmax(int n)
{
	if(n < 0)
		return maximum_number;
	else
	{
		if(arr[n] > maximum_number)
			maximum_number = arr[n];
		printmax(n-1); // recursive call
	}
}

		
		
	
	
