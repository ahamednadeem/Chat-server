/* a program to print a histogram of the lengths of words */

/*#include <stdio.h>

void main()
{
	int c;
	while((c = getchar()) != EOF)
	{
		if(c == ' ' || c == '\t' || c == '\n')
			putchar('\n');
		else
			putchar('*');
	}
}
			

*/

#include <stdio.h>
#include<stdlib.h>

#define MAXLEN  20 
#define IN      1   // inside a word 
#define OUT     0   // outside a word 

int main()
{
    int c, state, i, j, counter;
    int histogram[MAXLEN+1];

    for (i = 0; i < MAXLEN; ++i)
        histogram[i] = 0;
    state = OUT;
    counter = 0;
    
    while ((c = getchar()) != EOF)
        if (c == ' ' || c == '\n' || c == '\t') 
        {
            if (state == IN && counter > 0) 
            {
                if (counter <= MAXLEN)
                    ++histogram[counter-1];
                else
                {
                    printf("Word limit Exceeded");
                    exit(0);
                }
            }
            
            state = OUT;
            counter = 0;
        }
        
        else 
        {
            ++counter;
            if (state == OUT)
                state = IN;
        }



    for (i = 0; i < MAXLEN; ++i) 
    {
    	printf(" %d -->", i+1);
        
        for (j = 0; j < histogram[i]; ++j)
            putchar('*');
        putchar('\n');
    }
   
}
