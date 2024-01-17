#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DEFLINES 10 
#define LINES 100   
#define MAXLEN 100    

int mgetline(char *, int);

int main(int argc, char *argv[]) 
{
    char *p, *buf, *bufend;

    char line[MAXLEN];
    char *lineptr[LINES];  //pointer to read lines

    int first, i, last, len, n, nlines;

    if (argc == 1)
        n = DEFLINES;
    else if (argc == 2 && (*++argv)[0] == '-')
        n = atoi(argv[0]);
    else
    {
        printf("Error");
        exit(1);
    }
        

    if (n < 1 || n > LINES)
        n = LINES;

    for (i = 0; i < LINES; i++)
        lineptr[i] = NULL;

    if((p = buf = malloc(LINES * MAXLEN)) == NULL)
    {
    	printf("Memory Allocation Error \n");
    	exit(1);
    }
    	
    bufend = buf + LINES*MAXLEN;

    last = 0;
    nlines = 0;

    while ((len = mgetline(line, MAXLEN)) > 0) 
    {
        if (p + len + 1 >= bufend)
            p = buf;
        lineptr[last] = p;

        strcpy(lineptr[last], line);
        
        if (++last >= LINES)
            last = 0;

        p += len + 1;
        nlines++;
    }

    if (n > nlines)
        n = nlines;

    first = last - n;

    if (first < 0)
        first += LINES;

    for (i = first; n-- > 0; i = (i + 1) % LINES)
        printf("%s", lineptr[i]);

    return 0;
}


int mgetline(char s[], int lim) 
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') 
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}
