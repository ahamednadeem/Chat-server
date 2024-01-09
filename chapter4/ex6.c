#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include<math.h>


#define MAX_OPERATOR 100
#define OPERAND '0'
#define BUFFER_SIZE 100
#define MAX_STACK_SIZE 100

char buffer[BUFFER_SIZE];
int buffer_index = 0;
int stack_pointer = 0;
double stack[MAX_STACK_SIZE];

int get_operator(char[]);
void push(double);
double pop(void);

int get_character(void);
void unget_character(int);

int main(void) 
{
    int operator_type, previous_operator = 0;
    double operand2, result;
    char input[MAX_OPERATOR];
    double variables[26];

    while ((operator_type = get_operator(input)) != EOF) 
    {
        switch (operator_type) {
            case OPERAND:
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
                if (previous_operator >= 'A' && previous_operator <= 'Z')
                    variables[previous_operator - 'A'] = pop();
                else
                    printf("error: no variable name\n");
                break;
            case '\n':
                result = pop();
                printf("\t%.8g\n", result);
                break;
            default:
                if (operator_type >= 'A' && operator_type <= 'Z')
                    push(variables[operator_type - 'A']);
                else if (operator_type == 'v')
                    push(result);
                else
                    printf("error: unknown command %s\n", input);
                break;
        }
        previous_operator = operator_type;
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
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int get_operator(char input[]) 
{
    int character, index = 0;

    while ((input[0] = character = get_character()) == ' ' || character == '\t');

    input[1] = '\0';
    if (!isdigit(character) && character != '.')
        return character;

    index = 0;
    if (isdigit(character))
        while (isdigit(input[++index] = character = get_character()));

    if (character == '.')
        while (isdigit(input[++index] = character = get_character()));

    input[index] = '\0';
    if (character != EOF)
        unget_character(character);

    return OPERAND;
}

int get_character(void) 
{
    return (buffer_index > 0) ? buffer[--buffer_index] : getchar();
}

void unget_character(int c) 
{
    if (buffer_index >= BUFFER_SIZE)
        printf("unget_character: too many characters\n");
    else
        buffer[buffer_index++] = c;
}

