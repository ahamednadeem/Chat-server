#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_STACK_SIZE 100
#define NUMBER '0'
#define BUFSIZE 100
#define COMMAND '1'

int stack_pointer;
double stack[MAX_STACK_SIZE];
char buffer[100];
int buffer_index = 0;

void push(double value);
double pop(void);
int get_token(char token[]);
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
    char token[100];

    while ((type = get_token(token)) != EOF) 
    {
        switch (type) 
        {
            case NUMBER:
                push(atof(token));
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
                printf("error: unknown command or invalid input %s\n", token);
                break;
        }
    }

    return 0;
}

void push(double value) 
{
    if (stack_pointer < MAX_STACK_SIZE)
        stack[stack_pointer++] = value;
    else
        printf("error: stack full, can't push %g\n", value);
}

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

int get_token(char token[]) 
{
    int character, index = 0;

    while ((token[0] = character = getch()) == ' ' || character == '\t');
    token[1] = '\0';

    if (!isdigit(character) && character != '.' && character != '-') {
        return character;
    }

    if (character == '-' || isdigit(character)) {
        while (isdigit(token[++index] = character = getch()));
    }

    if (character == '.') {
        while (isdigit(token[++index] = character = getch()));
    }

    token[index] = '\0';

    if (character != EOF) {
        ungetch(character);
    }

    return (strcmp(token, "-") == 0) ? '-' : NUMBER;
}

void print_top(void) 
{
    if (stack_pointer > 0)
        printf("Top of stack: %.8g\n", stack[stack_pointer - 1]);
    else
        printf("error: stack empty\n");
}

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

void clear_stack(void) 
{
    stack_pointer = 0;
    printf("Stack cleared\n");
}

char buf[BUFSIZE];
int bufp = 0;

int getch(void) 
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) 
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

