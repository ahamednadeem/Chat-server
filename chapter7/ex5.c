/* postfix calculator to use scanf to do
the input and number conversion. */

#include <stdio.h>
#include <stdlib.h> // for atof()
#include <ctype.h>



#define MAXOP 100 // maximum number of operators and operands
#define NUMBER 0  // to depict the  number
#define MAXVAL 100 // maximum stack size
#define BUFSIZE 100 // maximum buffer size

/* function prototypes */
int get_operator(char[]);
void push(double);
double pop();
int getch(void);
void ungetch(int);

int stack_pointer = 0;  // marks the index of the stack
double stack[MAXVAL]; 

int buffer_pointer = 0; // marks the index of the buffer
char buf[BUFSIZE];

// reverse Polish calculator 
void main() 
{
    int type;
    double op2;
    char s[MAXOP];
    while ((type = get_operator(s)) != EOF) 
    {
        switch (type) 
        {
            case NUMBER:
                push(atof(s));  //push the converted string to integer to the stack
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
                    printf("zero division error\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
}





void push(double f)  // push the value into the stack
{
    if (stack_pointer < MAXVAL)
        stack[stack_pointer++] = f;
    else
        printf("stack full, cant push %g\n", f);
}

double pop(void)  // retrive the value from the stack if available (pop)
{
    if (stack_pointer > 0)
        return stack[--stack_pointer];
    else {
        printf("stack empty\n");
        return 0.0;
    }
}


int get_operator(char s[])    // get the next operator or operand
{
    int i, character;

    while ((s[0] = character = getch()) == ' ' || character == '\t');  //skips white space and tabs 

    i = 0;
    
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
        while (isdigit(s[++i] = (character = getch())));

    if (character == '.')
        while (isdigit(s[++i] = (character = getch())));

    s[i] = '\0';
    
    if (character != EOF)
        ungetch(character);
        
    return NUMBER;
}

int getch(void)   // retrives data from the user using scanf insted of getchar()
{
    char character;
    if (buffer_pointer > 0) 
        return buf[--buffer_pointer];
    else 
    {
        scanf("%c", &character);
        return character;
    }
}

void ungetch(int c) // stores the input c into the buffer
{
    if (buffer_pointer >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[buffer_pointer++] = c;
}
