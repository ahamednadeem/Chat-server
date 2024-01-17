#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define NUMERIC 1    
#define DECR 2   
#define LINES 100 
#define FOLD 4
#define MAXLEN 1000    

int charcmp(char *, char *);
int numcmp(char *, char *);
int readlines(char *lineptr[], int maxlines);
void myqsort(void *v[], int left, int right, int (*comp)(void *, void *));
void writelines(char *lineptr[], int nlines, int decr);
int mgetline(char *, int);
char *alloc(int);

#define ALLOCSIZE 1000   
static char allocbuf[ALLOCSIZE];    /* storage for alloc */
static char *allocp = allocbuf;       

static char option = 0;

int main(int argc, char *argv[]) 
{
    char *lineptr[LINES];
    int nlines;        /* pointer to text lines */
    int c;

    while (--argc > 0 && (*++argv)[0] == '-')
        while (c = *++argv[0])
            switch (c) 
            {
                case 'n': 
                    option |= NUMERIC;
                    break;
                case 'r': 
                    option |= DECR;
                    break;
                case 'f': 
                    option |= FOLD;
                    break;
                default:
                    printf("sort:illegal option %c\n", c);
                    exit(1);
            }
            
    if ((nlines = readlines(lineptr, LINES)) > 0) 
    {
            if (option & NUMERIC)
            	myqsort((void **) lineptr, 0, nlines - 1, (int (*)(void *, void *)) numcmp);
            else if(option & FOLD)
            	myqsort((void **) lineptr, 0, nlines - 1, (int (*)(void *, void *)) charcmp);
            else
            	myqsort((void **) lineptr, 0, nlines - 1, (int (*)(void *, void *)) strcmp);
        writelines(lineptr, nlines, option & DECR);
    } 
    else 
    {
        printf("input too big to sort \n");
        
    }
    return 0;
}

//return < 0 if s <t, =0 if s =t,> 0 if s > t 
int charcmp(char *s, char *t)
{
	for(; tolower(*s) == tolower(*t); s++, t++)
		if(*s == '\0')
			return 0;
	return tolower(*s) - tolower(*t);
}



void writelines(char *lineptr[], int nlines, int decr) {
    int i;
    if (decr)    /* print in decreasing order */
        for (i = nlines - 1; i >= 0; i--)
            printf("%s\n", lineptr[i]);
    else
        for (i = 0; i < nlines; i++)
            printf("%s\n", lineptr[i]);
}


int numcmp(char *s1, char *s2) 
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);

    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}




int readlines(char *lineptr[], int maxlines) 
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = mgetline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else 
        {
            line[len - 1] = '\0';    //deleted new line
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}




char *alloc(int n)    
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } 
    else
        return 0;
}



void myqsort(void *v[], int left, int right, int (*comp)(void *, void *)) 
{
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right)
        return;

    swap(v, left, (left + right) / 2);

    last = left;

    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);

    myqsort(v, left, last - 1, comp);
    myqsort(v, last + 1, right, comp);
}

void swap(void *v[], int i, int j) 
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int mgetline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}
