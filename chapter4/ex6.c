#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXVAL 100
#define NUMBER '0'
#define BUFFER_SIZE 100

char buf[BUFFER_SIZE];
int buffer_index = 0;
int stack_pointer = 0;
double stack[MAXVAL];

int getop(char[]);
void push(double);
double pop(void);

int getch(void);
void ungetch(int);

int main(void) 
{
    int type, previous_type = 0;
    double operand2, result;
    char input[MAXVAL];
    double variables[26];

    while ((type = getop(input)) != EOF) 
    {
        switch (type) {
            case NUMBER:
                push(atof(input));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                operand2 = pop();
                push(pop() - operand2);
                break;
            case '/':
                operand2 = pop();
                if (operand2 != 0.0)
                    push(pop() / operand2);
                else
                    printf("error: zero divisor\n");
                break;
            case '=':
                pop();
                if (previous_type >= 'A' && previous_type <= 'Z')
                    variables[previous_type - 'A'] = pop();
                else
                    printf("error: no variable name\n");
                break;
            case '\n':
                result = pop();
                printf("\t%.8g\n", result);
                break;
            default:
                if (type >= 'A' && type <= 'Z')
                    push(variables[type - 'A']);
                else if (type == 'v')
                    push(result);
                else
                    printf("error: unknown command %s\n", input);
                break;
        }
        previous_type = type;
    }
    return 0;
}

void push(double value) 
{
    if (stack_pointer < MAXVAL)
        stack[stack_pointer++] = value;
    else
        printf("error: stack full, can't push %g\n", value);
}

double pop(void) 
{
    if (stack_pointer > 0)
        return stack[--stack_pointer];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getop(char input[]) 
{
    int character, i = 0;

    while ((input[0] = character = getch()) == ' ' || character == '\t');

    input[1] = '\0';
    if (!isdigit(character) && character != '.')
        return character;

    i = 0;
    if (isdigit(character))
        while (isdigit(input[++i] = character = getch()));

    if (character == '.')
        while (isdigit(input[++i] = character = getch()));

    input[i] = '\0';
    if (character != EOF)
        ungetch(character);

    return NUMBER;
}

int getch(void) 
{
    return (buffer_index > 0) ? buf[--buffer_index] : getchar();
}

void ungetch(int c) 
{
    if (buffer_index >= BUFFER_SIZE)
        printf("ungetch: too many characters\n");
    else
        buf[buffer_index++] = c;
}

