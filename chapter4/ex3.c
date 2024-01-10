#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define BUFSIZE 100
#define MAXVAL 100

int stack_pointer = 0;
int buffer_pointer = 0; 
double val[MAXVAL];
char buf[BUFSIZE];


int getch(void); 
void ungetch(int);
int getop(char[]);
void push(double);
double pop(void);

int main(void) {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
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

/*push a value onto the stack */
void push(double f) {
    if (stack_pointer < MAXVAL)
        val[stack_pointer++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/*pop and return a value from the stack */
double pop(void) {
    if (stack_pointer > 0)
        return val[--stack_pointer];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/*get the next operator or operand */
int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-')
        return c; 

    i = 0;

    if (c == '-' || isdigit(c))
        while (isdigit(s[++i] = c = getch()));

    if (c == '.')
        while (isdigit(s[++i] = c = getch()));

    s[i] = '\0';

    if (c != EOF)
        ungetch(c);
   
    return NUMBER;
}

/* push character back on input */
void ungetch(int c) 
{
    if (buffer_pointer >= BUFSIZE)
        printf("too many characters\n");
    else
        buf[buffer_pointer++] = c;
}

/* get a (possibly pushed back) character */
int getch(void) 
{
    return (buffer_pointer > 0) ? buf[--buffer_pointer] : getchar();
}

