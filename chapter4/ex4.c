#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAXVAL 100
#define NUMBER '0'
#define BUFSIZE 100

int stack_pointer = 0;
double stack[MAXVAL];
char buf[BUFSIZE];
int buffer_pointer = 0; 


void push(double value);
double pop(void);
int getop(char token[]);
void print_top(void);
void duplicate_top(void);
void swap_top_two(void);
void clear_stack(void);
int getch(void);
void ungetch(int c);

int main(void) 
{
    int type;
    double op2;
    char s[MAXVAL];

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
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("error: zero divisor\n");
                break;
            case 'p':
                print_top();
                break;
            case 'd':
                duplicate_top();
                break;
            case 's':
                swap_top_two();
                break;
            case 'c':
                clear_stack();
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command or invalid input %s\n", s);
                break;
        }
    }

    return 0;
}

/* push a value onto the stack */
void push(double value) 
{
    if (stack_pointer < MAXVAL)
        stack[stack_pointer++] = value;
    else
        printf("error: stack full, can't push %g\n", value);
}

/* pop and return a value from the stack */
double pop(void) 
{
    if (stack_pointer > 0)
        return stack[--stack_pointer];
    else 
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* get the next operator or operand */
int getop(char s[]) 
{
    int character, i = 0;

    while ((s[0] = character = getch()) == ' ' || character == '\t');
    s[1] = '\0';

    if (!isdigit(character) && character != '.' && character != '-') 
    {
        return character;
    }

    if (character == '-' || isdigit(character)) 
    {
        while (isdigit(s[++i] = character = getch()));
    }

    if (character == '.') 
    {
        while (isdigit(s[++i] = character = getch()));
    }

    s[i] = '\0';

    if (character != EOF) 
    {
        ungetch(character);
    }

    return NUMBER;
}

/* print the top element of the stack */
void print_top(void) 
{
    if (stack_pointer > 0)
        printf("Top of stack: %.8g\n", stack[stack_pointer - 1]);
    else
        printf("error: stack empty\n");
}

/* duplicate the top element of the stack */
void duplicate_top(void) 
{
    if (stack_pointer > 0) 
    {
        double top_value = stack[stack_pointer - 1];
        push(top_value);
        printf("Duplicated top of stack: %.8g\n", top_value);
    } else 
    {
        printf("error: stack empty\n");
    }
}

/* swap the top two elements of the stack */
void swap_top_two(void) 
{
    if (stack_pointer >= 2) 
    {
        double top_value = pop();
        double second_value = pop();
        push(top_value);
        push(second_value);
        printf("Swapped top two elements of stack\n");
    } else 
    {
        printf("error: insufficient elements in stack to swap\n");
    }
}

/* clear all elements from the stack */
void clear_stack(void) 
{
    stack_pointer = 0;
    printf("Stack cleared\n");
}

char buf[BUFSIZE];
int bufp = 0;

/* get a (possibly pushed back) character */
int getch(void) 
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c) 
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

