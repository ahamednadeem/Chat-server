/* Write a routine ungets(s) that will push back an entire string onto the input. */

#include <stdio.h>
#include <string.h>

#define MAXBUF 1000
#define MAXLINE 1000

int bufp = 0;
int buf[MAXBUF];

int getch(void);
void ungetch(int c);
void ungets(char s[]); 
int mgetline(char line[], int maxline);

int main(void) 
{
    char line[MAXLINE];
    int c;
    mgetline(line, MAXLINE);
    ungets(line);

    while ((c = getch()) != EOF)
        putchar(c);

    return 0;
}

int mgetline(char s[], int lim)   // get input line by line from the user
{
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
}

void ungets(char s[])   // pushes back the entire string to the input
{
    int i;
    i = strlen(s);
    while (i > 0) 
        ungetch(s[--i]);  // now ungetch() is called and line is stored character by character in the buffer
}

void ungetch(int c)   // push the value into the buffer
{
    if (bufp >= MAXBUF)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int getch(void)   // get input from buffer or from getchar()
{ 
	return (bufp > 0) ? buf[--bufp] : getchar(); 
}
