#include <stdio.h>
#include<stdlib.h>

#define MAXLINE 100 
#define TABINC 5
#define YES 1
#define NO 0

void esettab(int argc, char *argv[], char *tab);
void entab(char *tab);
int mtabpos(int pos, char *tab);

int main(int argc, char *argv[]) 
{
    char tab[MAXLINE];
    esettab(argc, argv, tab);
    entab(tab);
    
    return 0;
}


void esettab(int argc, char *argv[], char *tab) 
{
    int i, inc, pos;

    if (argc <= 1) //default tab stops
        for (i = 1; i < MAXLINE; i++)
            if (i % TABINC == 0)
                tab[i] = YES;
            else
                tab[i] = NO;
    else if (argc == 3 && *argv[1] == '-' && *argv[2] == '+') //user provided range
    {
        pos = atoi(&(*++argv)[1]);
        inc = atoi(&(*++argv)[1]);

        for (i = 1; i < MAXLINE; i++)
            if (i != pos)
                tab[i] = NO;
            else 
            {
                tab[i] = YES;
                pos += inc;
            }
    } 
    else 
    {
        for (i = 1; i < MAXLINE; i++)
            tab[i] = NO; 

        while (--argc > 0) 
        {
            pos = atoi(*++argv);
            if (pos > 0 && pos < MAXLINE)
                tab[pos] = YES;
        }
    }
}

void entab(char *tab)  //replace strings of blanks with tabs and spaces
{
    int c, pos;
    int nb = 0;    //no of blanks 
    int nt = 0;    //no of tabs

    for (pos = 1; (c = getchar()) != EOF; pos++)
        if (c == ' ') 
        {
            if (mtabpos(pos, tab) == NO)
                ++nb;
            else 
            {
                nb = 0;  //resetting no of blanks
                ++nt;    //increase no of tabs
            }
        } 
        else 
        {
            for (; nt > 0; nt--)
                putchar('\t'); 
            if (c == '\t')
                nb = 0;
            else
                for (; nb > 0; nb--)
                    putchar(' ');
            putchar(c);

            if (c == '\n')
                pos = 0;
            else if (c == '\t')
                while (mtabpos(pos, tab) != YES)
                    ++pos;
        }
}

int mtabpos(int pos, char *tab) 
{
    if (pos > MAXLINE)
        return YES;
    else
        return tab[pos];
}
