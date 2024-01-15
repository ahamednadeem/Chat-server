#include<stdio.h>
#include<string.h>

#define MAXLINES 1000   // max #lines to be sorted 

char *lineptr[MAXLINES];
char linestor[MAXLINES];

int readlines(char *lineptr[], char *linestor, int maxlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *v[], int left, int right);
int mgetline(char *, int);

void main() 
{
    int nlines;

    if ((nlines = readlines(lineptr, linestor, MAXLINES)) >= 0) 
    {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
    } 
    else 
        printf("error");
    
}

#define MAXLEN 1000 //maximum length of a line



int readlines(char *lineptr[], char *linestor, int maxlines) 
{
    int len, nlines;
    char line[MAXLEN];
    char *p = linestor;
    char *linestop = linestor + MAXLEN;

    nlines = 0;

    while ((len = mgetline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || p + len > linestop)
            return -1;
        else 
        {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    return nlines;
}

void writelines(char *lineptr[], int nlines) 
{
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

void qsort(char *v[], int left, int right) 
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);

    last = left;

    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}


void swap(char *v[], int i, int j) 
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}



int mgetline(char *s, int lim) 
{
    int character;
    char *t = s;  //storing starting address

    while (--lim > 0 && (character = getchar()) != EOF && character != '\n')
        *s++ = character;
    if (character == '\n')
        *s++ = character;

    *s = '\0';

    return s - t;
}
