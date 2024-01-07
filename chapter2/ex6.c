#include<stdio.h>

unsigned setbit(unsigned x, int p, int n, unsigned y);

int main()
{
	printf("%u", setbit((unsigned) 123, 3, 3, (unsigned) 42));
	
	return 0;
}	
	
	
	
	
	
	
unsigned setbit(unsigned x, int p, int n, unsigned y) 
{
    return x & ~(~(~0 << n) << (p + 1 - n)) | (y & (~(~0 << n)) << (p + 1 - n));
}
