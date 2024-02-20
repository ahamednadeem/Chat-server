/* Write the program expr , which evaluates a reverse Polish expression from the
command line, where each operator or operand is a separate argument. For example,
expr 2 3 4 + *
evaluates 2 * (3+4). */


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXOP 100  
#define NUMBER '0' 
#define BUFSIZE 100
#define MAXVAL 100 

int stack_pointer = 0;         
double stack[MAXVAL]; 
char buf[BUFSIZE];  
int buffer_pointer = 0;       
int getop(char[]);
void ungets(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int main(int argc, char *argv[])  // we will give input from the command line itself 
{
    char s[MAXOP];
    double op2;

    while (--argc > 0) 
    {
        ungets(" "); 
        ungets(*++argv);  //storing the expression in buffer

        switch (getop(s)) 
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
                else
                    printf("error: zero divisor \n");
                break;
            default:
                printf("error: unknown command %s \n", s);
                argc = 1;
                break;
        }
    }
    printf("\t %8g\n", pop());

    return 0;
}

int getop(char s[]) 
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t');

    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c;

    i = 0;

    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()));
    if (c == '.') 
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';

    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

int getch(void)
{
	return (buffer_pointer > 0) ? buf[--buffer_pointer] : getchar();
}


void ungetch(int c) 
{
    if (buffer_pointer >= BUFSIZE)
        printf("ungetch: too many characters \n");
    else
        buf[buffer_pointer++] = c;
}


void push(double f) 
{
    if (stack_pointer < MAXVAL)
        stack[stack_pointer++] = f;
    else
        printf("error: stack full, can't push %g \n", f);
}


double pop(void) 
{
    if (stack_pointer > 0)
        return stack[--stack_pointer];
    else {
        printf("error: stack empty \n");
        return 0.0;
    }
}


void ungets(char s[]) 
{
    int len = strlen(s);

    while (len > 0)
        ungetch(s[--len]);
}
