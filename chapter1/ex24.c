#include <stdio.h>

int brace, brack, paren;
void search(int c);

int main() 
{
    int c;

    extern int brace, brack, paren;

    while ((c = getchar()) != EOF)
       search(c);

    if (brace < 0) 
    {
        printf("Unmatched Braces\n");
        brace = 0;
    } 
    else if (brack < 0) 
    {
        printf("Unmatched brackets\n");
        brack = 0;
    } 
    else if (paren < 0) 
    {
        printf("Unmatched parenthesis\n");
        paren = 0;
    }

    if (brace > 0)
        printf("Unmatched braces\n");
    else if (brack > 0)
        printf("Unmatched brackets\n");
    else if (paren > 0)
        printf("Unmatched parenthesis\n");

    return 0;
}


void search(int c)
{
    extern int brace, brack, paren;

    if (c == '{')
        --brace;
    else if (c == '}')
        ++brace;
    else if (c == '[')
        --brack;
    else if (c == ']')
        ++brack;
    else if (c == '(')
        --paren;
    else if (c == ')')
        ++paren;
}
