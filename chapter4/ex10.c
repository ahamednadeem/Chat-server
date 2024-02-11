/* getline to read an entire input line; this makes
getch and ungetch unnecessary. Revise the calculator to use this approach. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUMBER '0'  // this indictes a number
#define MAXVAL 1000
#define MAXLINE 1000

int getop(char[]);
void push(double);
int mgetline(char line[], int limit);
double pop(void);

int stack_pointer = 0;
double val[MAXVAL];

int li = 0;
char line[MAXLINE];

int main(void) 
{
    int type;
    double op2;
    char s[MAXLINE];  

    while ((type = getop(s)) != EOF) 
    {
        switch (type) 
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                break;
            case '\n':
                printf("\t%.9g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

void push(double f) 
{
    if (stack_pointer < MAXVAL)
        val[stack_pointer++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void) 
{
    if (stack_pointer > 0)
        return val[--stack_pointer];
    else 
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getop(char s[])  // get input operator and operand from the user
{
    int character, i;

    if (line[li] == '\0')
        if (mgetline(line, MAXLINE) == 0)  // calling mgetline
            return EOF;
        else
            li = 0;

    while ((s[0] = character = line[li++]) == ' ' || character == '\t');  // we get the input to the line and read the characters from the line
									   // hence we have eliminated the use of getch() and ungetch()
    s[1] = '\0';

    if (!isdigit(character) && character != '.')
        return character;

    i = 0;

    if (isdigit(character))
        while (isdigit(s[++i] = character = line[li++]));
    if (character == '.')
        while (isdigit(s[++i] = character = line[li++]));

    s[i] = '\0';
    li--;

    return NUMBER;
}

int mgetline(char s[], int lim)  // get input line from the user and store it in a character array
{
    int i, character;

    for (i = 0; i < lim - 1 && (character = getchar()) != EOF && character != '\n'; ++i)
        s[i] = character;

    if (character == '\n')
        s[i++] = character;

    s[i] = '\0';

    return i;
}

