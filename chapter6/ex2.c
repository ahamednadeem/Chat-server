#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define YES      1
#define NO       0

struct tnode 
{  
    char *word;            //points to text
    int match;            
    struct tnode *left;    //left child
    struct tnode *right;   //right child
};

struct tnode *addtree(struct tnode *, char *, int, int *);
void treeprint(struct tnode *);
int getword(char *, int);
int getch(void);
void ungetch(int);
int in_comment(void);

int main(int argc, char **argv)
{
    struct tnode *root;
    char word[MAXWORD];
    int num;
    int find = NO;
    if(argc <= 1 || argc > 2 || atoi(*(argv+1)) > 0)  //there must be only 2 arguments
        num = 6;
    else
        num = abs(atoi(*(argv+1)));   //from command line
    
    printf("num = %d\n", num);
        
    root = NULL;
    while(getword(word, MAXWORD) != EOF)
    {
        if(isalpha(word[0]) && strlen(word) >= num)
            root = addtree(root, word, num, &find);
        find = NO;
    }
    treeprint(root);
    return 0;
}

struct tnode *talloc(void);
int compare(char *, struct tnode *, int, int *);
char *s_dup(char *s);

struct tnode *addtree(struct tnode *p, char *w, int num, int *find)
{
    int cond;
    
    if(p == NULL) //a new word has arrived
    {
        p = talloc(); //make a new node
        p->word = s_dup(w);
        p->match = *find;
        p->left = p->right = NULL;
    }
    else if((cond = compare(w, p, num, find)) < 0)
        p->left = addtree(p->left, w, num, find);
    else if(cond > 0)
        p->right = addtree(p->right, w, num, find);
    return p;
}

int compare(char *s, struct tnode *p, int num, int *find)
{
    int i;
    char *t = p->word;
    for(i = 0; *s == *t; i++, s++, t++)
        if(*s == '\0')
            return 0;
    if(i >= num)
    {
        *find = YES;
        p->match = YES;
    }
    return *s - *t;
}

void treeprint(struct tnode *p)
{
    if(p != NULL)
    {
        treeprint(p->left);
        if(p->match)
            printf("%s\n", p->word);
        treeprint(p->right);
    }
}

#include <stdlib.h>


struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}


char *s_dup(char *s)
{
    char *p;
    
    p = (char *)malloc(strlen(s)+1);      // +1 for '\0'
    if(p != NULL)
        strcpy(p, s);
    return p;
}

#define BUFSIZE 100

char buf[BUFSIZE];         
int bufp = 0;              

int getch(void) 
{
   return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) 
{
    if(bufp >= BUFSIZE)
        printf("too many characnters\n");
    else
        buf[bufp++] = c;
}

int getword(char *word, int lim)    //get input words from the user
{
    int c, d; 
    char *w = word;
    
    while(isspace(c = getch()));
    if(c != EOF)
        *w++ = c;
    if(isalpha(c) || c == ' ' || c == '#')
    {
        for(;--lim > 0; w++)
            if(!isalnum(*w= getch()) && *w != '_')
            {
                ungetch(*w);
                break;
            }
    }
    else if(c=='\'' || c == '"')
    {
        for(; --lim > 0; w++)
            if((*w = getch()) == '\\')
                *++w = getch();
            else if(*w == c)
            {
                w++;
                break;
            }
            else if(*w == EOF)
                break;
    }
    else if(c == '/')
    {
        if(((d = getch()) == '*'))
            c = in_comment();
        else
            ungetch(d);
    }
    *w = '\0';
    return c;
}

int in_comment(void)
{
    int c;
    
    while((c = getch()) != EOF)
        if(c == '*')
        {
            if((c = getch()) == '/')
                break;
            else
                ungetch(c);
        }
    return c;
}
