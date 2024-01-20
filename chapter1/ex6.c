/* Verify that the expression getchar() != EOF is 0 or 1. */


#include <stdio.h>
void main()
{
char c;                      
while(c = getchar() != EOF)  // Initially the character obtained from the getchar is checked if it is EOF is not (1 or 0 is the result), then assigned to c
	printf("%d \n", c);
printf("AT EOF: %d \n ", c); // Must be 0
}

