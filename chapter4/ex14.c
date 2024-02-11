/* Define a macro swap(t,x,y) that interchanges two arguments of type t . */

#include<stdio.h>

#define swap(t, x, y) { t z; z = y; y = x; x = z; }  //z is of type t, where z is a temporary variable

void main()
{
	int x, y;
	x = 2;
	y = 3;
	printf("x = %d y = %d \n", x, y);
	swap(int, x, y);
	
	printf("x = %d y = %d \n", x, y);
}

