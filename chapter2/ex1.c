/* program to determine the ranges of char , short , int , and long
variables, both signed and unsigned  */

#include <stdio.h>
void printUnsignedRange(size_t bytes)
{
	int bits = 8 * bytes;
	unsigned int to =  2 * (1 << (bits -1)) - 1;
	printf(" range is from %u to %u \n", 0, to);
}

void printSignedRange(size_t bytes)
{
	int bits = 8*bytes;
	int from = -(1 << (bits-1));
	int to = (1 << (bits-1)) - 1;
	printf(" range is from %d to %d\n", from, to);
}

int main()
{
	printf("signed char: ");
	printSignedRange(sizeof(signed char));
	
	printf("signed int: ");
	printSignedRange(sizeof(signed int));
	
	printf("signed short int: ");
	printSignedRange(sizeof(signed short int));
	

	printf("\n");	
	
	printf("unsigned char: ");
	printUnsignedRange(sizeof(unsigned char));

	printf("unsigned int: ");
	printUnsignedRange(sizeof(unsigned int));

	printf("unsigned short int: ");
	printUnsignedRange(sizeof(unsigned short int));
	

	return 0;
}

