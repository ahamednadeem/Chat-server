/* program that will print arbitrary input in a sensible way. As a minimum,
it should print non-graphic characters in octal or hexadecimal according to local custom, and
break long text lines. */

#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100 // maximum number of chars in one line 
#define OCTLEN 6    // length of an octal value + width of 3

//increment position counter for output 
int inc(int pos, int n) 
{ 
    if (pos + n < MAXLINE)
        return pos + n;
    else 
    {
        putchar('\n');  //line limit reached hence we go to newline
        return n;
    }
}

int main(void) 
{
    int c, pos;

    pos = 0; 

    while ((c = getchar()) != EOF)
        if (iscntrl(c) || c == ' ') //iscntrl checks if it is a non-graphic character
        {
            pos = inc(pos, OCTLEN);
            printf("%03o", c);
            										
            				// newline character 
          if (c == '\n')
          {
                pos = 0;
            	putchar('\n');
          } 
          }
        else 
        {
            // graphic character - which can be displayed
            pos = inc(pos, 1);
            putchar(c);
        }
        
    return 0;
}

