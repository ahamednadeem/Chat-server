/*  there will never be more than one character of pushback. Modify
getch and ungetch accordingly. */

#include<stdio.h>

int getch(void);
void ungetch(int c);

int buf = 0; //buffer is no longer an array, because maximum of only one character push back is there

int main() 
{
    int c = 'a';
    ungetch(c);
    while ((c = getch()) != EOF) 
    {
        putchar(c);
    }
    return 0;
}


int getch(void)  // get input from the buf or from getchar()
{
	int c;
	if(buf != 0)
		c = buf;
	else
		c = getchar();
	buf = 0;  // re-initialised buf to 0, hence buf is ready to store the next value
	return c;
}
 
void ungetch(int c)  // updates the value of the buf only if buf is 0
{
	if(buf != 0)
		printf("Only one character at a time: ");
	else
		buf = c;
}


		

	
	
