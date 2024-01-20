/* Write a program to print the value of EOF . */

#include<stdio.h>
void main()
{
	printf("The value of EOF is: %d \n", EOF);
	
	int c;
	
	while((c = getchar()) != EOF);   // until we get EOF
	printf("EOF : %d ", c);
}

