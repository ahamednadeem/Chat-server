/* Functions like isupper can be implemented to save space or to save time.
Explore both possibilities. */

#include<stdio.h>
#define isupper2(c) (((c) >= 'A' && (c) <= 'Z') ? 1 : 0) //this saves time but consumes more memory


//this version saves space
int isupper1(char character)
{
	if(character >= 'A' && character<= 'Z')
	       return 1;
	else
		return 0;
}

int main()
{
	char s[] = "ABCDabcd";
	char *p = s;
	
	while(*p != '\0')
	{
		if(isupper1(*p))
			printf("It is in Uppercase\n\n");
		else
			printf("It is in Lowercase\n\n");
			
		if(isupper2(*p))
			printf("It is in uppercase\n\n");
			
		else
			printf("It is in lowercase\n\n");
		*p++;
	}
	
	return 0;
}



