#include<stdio.h>

int getch(void);
void ungetch(int c);

int buf = 0; //buffer is no longer an array

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


int getch(void)
{
	int c;
	if(buf != 0)
		c = buf;
	else
		c = getchar();
	buf = 0;
	return c;
}

void ungetch(int c)
{
	if(buf != 0)
		printf("Only one character at a time: ");
	else
		buf = c;
}


		

	
	
