/*
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define buffersize 100
#define MAXOP 100
#define MAXVAL 100
#define NUMBER '0'

int stack_pointer = 0;
int buffer_pointer = 0;

char buff[buffersize];
double val[MAXVAL];

int getch(void);
void ungetch(int);
double pop(void);
void push(double);
int getop(char[]);



int main()
{
	int type;
	double op1;
	double op2;
	char s[MAXOP];
	
	while((type  = getop(s)) != EOF)
	{
		switch(type)
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
				op1 = pop();
				push(op1 - op2);
				break;
			case '/':
				op2  = pop();
				op1 = pop();
				if(op2 != 0.0)
					push(op1 / op2);
				else
					printf("Zero division error\n");
				break;
			case '%':
				op2 = pop();
				op1 = pop();
				if(op2 != 0.0)
					//push(fmod(op1, op2));
					;
				else
					printf("can mod with 0\n");
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("Error");
				break;
				
		}
	}
return 0;
}



double pop(void)
{
	if(stack_pointer < MAXVAL)
		return val[--stack_pointer];
	else
	{
		printf("Empty stack\n");
		return 0.0;
	}
}

void push(double f)
{
	if(stack_pointer < MAXVAL)
		val[stack_pointer++] = f;
	else
		printf("Stack Full\n");
}




int getop(char s[])
{
	int character;
	while((s[0] = character = getch()) == ' ' || character == '\t');
	s[1] = '\0';
	if(!isdigit(character) && character != '-' && character != '.')
	return character; //since it's not a number

	int i = 0;
	
	if(character == '-' || isdigit(character))
		while(isdigit(s[++i] = character = getch()));
	if(character == '.')
		while(isdigit(s[++i] = character = getch()));
	s[i] = '\0';

	if(character != EOF)
		ungetch(character);

	if(strcmp(s, "-") == 0)
		return '-';


	return NUMBER;
}

void ungetch(int c)
{
	if(buffer_pointer >= buffersize)
		printf("To many characters\n");
	else
		buff[buffer_pointer++] = c;
}

int getch(void)
{
	return (buffer_pointer > 0) ? buff[--buffer_pointer] : getchar();
}

*/


#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'

#define BUFSIZE 100

#define MAXVAL 100

int sp = 0;
int bufp = 0;

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
                    printf("error:zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("erro:zero divisor\n");
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

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error:stack full, cant push %g\n", f);
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

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
    if (strcmp(s, "-") == 0)
        return '-';
    return NUMBER;
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int getch(void) 
{ 
	return (bufp > 0) ? buf[--bufp] : getchar(); 
}
