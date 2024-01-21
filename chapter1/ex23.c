/* Program to remove comments from a C Program. */

#include <stdio.h>

void iscomment(int);
void multiline_comment();  
void singleline_comment();


int main() 
{
    int character, d;

    while ((character = getchar()) != EOF)
        iscomment(character);

    return 0;
}

void iscomment(int c)    //to check if it is in comment or not
{
    int d;

    if (c == '/') 
    {
        if ((d = getchar()) == '*')
            multiline_comment();
        else if (d == '/') 
            singleline_comment();
        else 
        {
            putchar(c);
            putchar(d);
        }
    } 
    else
        putchar(c);
}

void multiline_comment()    //when it is in multiline comment
{
    int c, d;

    c = getchar();
    d = getchar();

    while (c != '*' || d != '/')    //if c == * and d == / only then this loop gets terminated and depicts the end of the loop
    {
        c = d;
        d = getchar();
    }
}

void singleline_comment()     //when it is in single line comment
	{
		while(getchar() != '\n');    //comment ends when we enter newline character
	}
	


