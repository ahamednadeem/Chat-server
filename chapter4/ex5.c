/* Add access to library functions like sin , exp , and pow */

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define NAME 'n'
#define BUFSIZE 100
#define MAXVAL 100

int stack_pointer = 0;
double stack[MAXVAL];
char buffer[BUFSIZE];
int buffer_pointer = 0;

int getch(void);
void ungetch(int);
int getop(char[]);
void push(double);
double pop(void);
void mathfnc(char[]);
void clear_stack(void);

int main(void)
{
    int type;
    double op2, op1;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case NAME:
            mathfnc(s);
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
        case '?':
            op2 = pop();
            printf("\t%.8g\n", op2);
            push(op2);
            break;
        case 'c':
            clear_stack();
            break;
        case 'd':
            op2 = pop();
            push(op2);
            push(op2);
            break;
        case 's':
            op1 = pop();
            op2 = pop();
            push(op1);
            push(op2);
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

void push(double f)   // push into the stack
{
    if (stack_pointer < MAXVAL)
        stack[stack_pointer++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)      // pop from the stack
{
    if (stack_pointer > 0)
        return stack[--stack_pointer];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void clear_stack(void)  // clears the stack
{
    stack_pointer = 0;
}


int getop(char s[])   // get input from the user
{ 
    int i, character;

    while ((s[0] = character = getch()) == ' ' || character == '\t');
    s[1] = '\0';

    i = 0;
    if (islower(character))
    {
        while (islower(s[++i] = character = getch()))
            ;
        s[i] = '\0';
        if (character != EOF)
            ungetch(character);
        if (strlen(s) > 1)
            return NAME;
        else
            return s[0];
    }

    if (!isdigit(character) && character != '.' && character != '-')
        return character;

    if (character == '-')
        if (isdigit(character = getch()) || character == '.')
            s[++i] = character;
        else
        {
            if (character != EOF)
                ungetch(character);
            return '-';
        }

    if (isdigit(character))
        while (isdigit(s[++i] = character = getch()))
            ;

    if (character == '.')
        while (isdigit(s[++i] = character = getch()))
            ;

    s[i] = '\0';
    if (character != EOF)
        ungetch(character);
    return NUMBER;
}

int getch(void)  // get input from the buffer or from getchar() function
{
    return (buffer_pointer > 0) ? buffer[--buffer_pointer] : getchar();
}

void ungetch(int c)  // store into the buffer
{
    if (buffer_pointer >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buffer[buffer_pointer++] = c;
}

void mathfnc(char s[])  // math functions added to the program
{
    double op2;
    if (strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if (strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if (strcmp(s, "pow") == 0)
    {
        op2 = pop();
        push(pow(pop(), op2));
    }
    else
        printf("error: %s is not supported\n", s);
}

