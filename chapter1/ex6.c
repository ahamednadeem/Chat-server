#include <stdio.h>
void main()
{

int c;
while(c = getchar() != EOF)
{
	printf("%d", c);
}
printf("AT EOF: \n");
printf("%d", c);

}

