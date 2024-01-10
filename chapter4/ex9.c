#include<stdio.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int c);

int buf[BUFSIZE];
int buffer_pointer = 0;

int main()
{
	int c;
	while((c = getch()))
	{
		putchar(c);
	}
	printf("%d\n", c);
	//printf("%d", EOF);
	return 0;
}

int getch(void)
{
	if(buffer_pointer > 0)
		return buf[--buffer_pointer];
	return getchar();
}

void ungetch(int c)
{
	if(buffer_pointer < BUFSIZE)
		buf[buffer_pointer++] = c;
	else
		printf("No space in buffer\n");
}


	

