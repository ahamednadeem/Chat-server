/* Rewrite appropriate programs from earlier chapters and exercises with pointers
instead of array indexing */

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define NUMBER '0' 
#define MAXVAL 100 
#define BUFSIZE 100
#define MAXLINE 1000
#define MAXOP 100

int getch(void);
void ungetch(int);
int getop(char *);
void push(double);
double pop(void);
int mgetline(char *s, int lim);
int matoi(char *);
void itoa(int n, char *s);
void reverse(char *);

int stack_pointer = 0;
int buffer_pointer = 0;
double stack[MAXVAL];
char buf[BUFSIZE];




int main(void) 
{
    char line[MAXLINE];
    char *s = "8723";
    int res;
    res = atoi(s);
    printf("%d\n", res);
    
    char s1[MAXVAL];
    int i = 873;
    itoa(i, s1);
    reverse(s1);
    printf("%s\n", s1);

   

    int type;
    double op2;
    char s3[MAXOP];

    while ((type = getop(s3)) != EOF) 
    {
        switch (type) 
        {
            case NUMBER:
                push(atof(s3));
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


int matoi(char *s) 
{
    int n, sign;
    for (; isspace(*s); s++);
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        s++;
    for (n = 0; isdigit(*s); s++)
        n = 10 * n + *s - '0';
    return sign * n;
}


void push(double f) 
{
    if (stack_pointer < MAXVAL)
        stack[stack_pointer++] = f;
    else
        printf("error: stack full,can't push %g\n", f);
}


double pop(void) 
{
    if (stack_pointer > 0)
        return stack[--stack_pointer];
    else 
    {
        printf("error: stack empty \n");
        return 0.0;
    }
}


int getop(char *s) 
{
    int c;
    while ((*s = c = getch()) == ' ' || c == '\t');
    *(s + 1) = '\0';
    if (!isdigit(c) && c != '.')
        return c;       
    if (isdigit(c))
        while (isdigit(*++s = c = getch()));
    if (c == '.')
        while (isdigit(*++s = c = getch()));
    *s = '\0';
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
        printf("ungetch: too many characters\n");
    else
        buf[buffer_pointer++] = c;
}

void itoa(int n, char *s) 
{
    int sign;
    char *t = s;

    if ((sign = n) < 0)
        n = -n;

    do 
    {
        *s = n % 10 + '0';
        s++;
    } 
    while ((n /= 10) > 0);

    if (sign < 0)
        *s++ = '-';
    *s = '\0';

}


void reverse(char *s) 
{
    int c;
    char *t;

    for (t = s + (strlen(s) - 1); s < t; s++, t--) 
    {
        c = *s;
        *s = *t;
        *t = c;
    }
}


int mgetline(char *s, int lim) 
{
    int c;
    char *t = s;

    while (--lim > 0 && (c = getchar()) != 'X' && c != '\n')
        *s++ = c;

    if (c == '\n')
        *s++ = c;
    *s = '\0';

    return s - t;
}




