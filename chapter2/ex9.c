#include<stdio.h>
int bitcount(unsigned int x);



void main()
{
	int x = 23;
	printf("The Number of 1's : %d \n ", bitcount(x));
}	

int bitcount(unsigned int x) 
{
    int count = 0;
    while (x != 0) 
    {
        x &= x-1;
        count++;
    }
    return count;
}
