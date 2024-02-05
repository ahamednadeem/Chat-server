/* x &= (x-1) deletes the rightmost 1-bit
in x . Use this observation to right a program for bitcount */

#include<stdio.h>
int bitcount(unsigned int x);

void main()
{
	int x = -923;
	printf("The Number of 1's : %d \n ", bitcount(x));
}	

int bitcount(unsigned int x) 
{
    int count = 0;
    while (x != 0) 
    {
        x &= (x-1);  //the rightmost one bit is deleted at each iteration
        count++;
    }
    return count;
}
