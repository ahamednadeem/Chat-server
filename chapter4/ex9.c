/* handle a pushed-back EOF correctly. */

#include<stdio.h>
#include<stdlib.h>


#define BUFSIZE 100

int getch(void);
void ungetch(int c);

int buf[BUFSIZE];
int buffer_pointer = 0;

int main()
{
	int c;
	while((c = getch()))  // Hence EOF is also Handles
	{
		if (c == EOF) {
			printf("%d\n", c);
			exit(0);
		}
			
		putchar(c);
	}
	printf("%d\n", c);
	//printf("%d", EOF);
	return 0;
}

int getch(void)  // get input from the buffer or from getchar()
{
	if(buffer_pointer > 0)
		return buf[--buffer_pointer];
	return getchar();
}

void ungetch(int c)  // store data into the buffer
{
	if(buffer_pointer < BUFSIZE)
		buf[buffer_pointer++] = c;
	else
		printf("No space in buffer\n");
}


	

