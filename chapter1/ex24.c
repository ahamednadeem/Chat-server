/* check a C program for rudimentary syntax errors like
unmatched parentheses, brackets and braces */

#include <stdio.h>

int brace, brack, paren;

void incomment();
void inquote(int c);
void search(int c);

int flag = 0;          
int brace, brack, paren;

int main(void) 
{
    int c;

    while ((c = getchar()) != EOF)
        if (c == '/')
            if ((c = getchar()) == '*')
                incomment();
            else
                search(c);
                
        else if (c == '\'' || c == '"')
            inquote(c);   
        else
            search(c);

    if (brace != 0) 
    {
        printf("Unmatched Braces\n");
        brace = 0;
        flag = 1;
    }
    if (brack != 0) 
    {
        printf("Unmatched brackets\n");
        brack = 0;
        flag = 1;
    } 
    if (paren != 0) 
    {
        printf("Unmatched parenthesis\n");
        paren = 0;
        flag = 1;
    }
	
    if(!flag)
    	printf("No errors");
    return 0;
}

void incomment() //when it is in comments
{
    int c, d;
    c = getchar();
    d = getchar();

    while (c != '*' || d != '/') 
    {
        c = d;
        d = getchar();
    }
}

void inquote(int c)   //when it is in quotes
{
    int d;
    while ((d = getchar()) != c);
}

void search(int c)   //searches for unmatched braces, brakets and paranthesis
{

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
