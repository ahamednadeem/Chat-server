/* implementation of stack */

#include<stdio.h>
#define limit 100

int pop();
void push(int);
void printstack();

int stack[100] = {0};
static int ind = 0;

int main()
{
	int p;
	printf("Implementing Stack\n");
	push(5);
	printstack();
	push(13);
	printstack();
	p = pop();
	
	return 0;
	
}


void push(int n)
{
	if(ind >= limit)
		printf("Stack Full\n");
	else
		stack[ind++] = n;
}

int pop()
{
	if (ind >= 0)
	{
		int i = stack[ind - 1];
		ind--;
		printf("Element popped: %d", i);
		return i;
	}
		
	else
	{
		printf("No element found in the stack\n");
		return -1;
	}
}
	
	
void printstack()
{
	printf("Printing stack\n");
	for(int i = 0; i < ind; i++)
	{
		printf("%d ", stack[i]);
	}
	printf("\n");
}


		
	

	
	
