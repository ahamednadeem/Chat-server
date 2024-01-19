#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
struct linklist                    
{
    int lnum;
    struct  linklist *ptr;
};

struct tnode                     
{ 
    char *word;                    //points to text
    struct linklist *lines;        //numbers string
    struct tnode *left;            //left child
    struct tnode *right;           //right child
};

struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
int getword(char *, int);
int noisewords(char *);

int main(int argc, char **argv)
{
    struct tnode *root;
    char word[MAXWORD];
    int linenum = 1;
    
    root = NULL;
    while(getword(word, MAXWORD) != EOF)
        if(isalpha(word[0]) && noisewords(word) == -1)  //removing if any noise words 
            root = addtree(root, word, linenum);
        else if(word[0] == '\n')
            linenum++;
    treeprint(root);
    return 0;
}

struct tnode *talloc(void);
struct linklist *lalloc(void);
char *s_dup(char *s);
void addline(struct tnode *, int);

struct tnode *addtree(struct tnode *p, char *w, int linenum)
{
    int cond;
    
    if(p == NULL)                 //a new word has arrived
    {
        p = talloc();             //make a new node
        p->word = s_dup(w);
        p->lines = lalloc();
        p->lines->lnum = linenum;
        p->lines->ptr = NULL;
        p->left = p->right = NULL;
    }
    else if((cond = strcmp(w, p->word)) == 0)
        addline(p, linenum);
    else if(cond < 0)
        p->left = addtree(p->left, w, linenum);
    else
        p->right = addtree(p->right, w, linenum);
    return p;
}

void addline(struct tnode *p, int linenum)
{
    struct linklist *temp;
    
    temp = p->lines;
    while(temp->ptr != NULL && temp->lnum != linenum)
        temp = temp->ptr;
    if(temp->lnum != linenum)
    {
        temp->ptr = lalloc();
        temp->ptr->lnum = linenum;
        temp->ptr->ptr = NULL;
    }
}   

void treeprint(struct tnode *p)
{
    struct linklist *temp;
    
    if(p != NULL)
    {
        treeprint(p->left);
        printf("%10s:", p->word);
        for(temp = p->lines; temp != NULL; temp = temp->ptr)
            printf("%4d", temp->lnum);
        printf("\n");
        treeprint(p->right);
    }
}

struct linklist *lalloc(void)
{
    return(struct linklist *) malloc(sizeof(struct linklist));
}


struct tnode *talloc(void)
{
    return(struct tnode *) malloc(sizeof(struct tnode));
}

char *s_dup(char *s)
{
    char *p;
    
    p = (char *)malloc(strlen(s)+1); // +1 for '\0'
    if(p != NULL)
        strcpy(p, s);
    return p;
}


int noisewords(char *w)    //To identify noise words
{
    static char *cw[] = {"a", "an", "are", "in", "is", "of", 
                        "or", "that", "the", "this", "to"};   //IN sorted order, we can do binary search
    int cond, mid;
    int low = 0;
    int high = sizeof(cw)/sizeof(char *) - 1;
    
    while(low <= high)
    {
        mid = (low + high)/2;
        if((cond = strcmp(w, cw[mid])) < 0)
            high = mid -1;
        else if(cond > 0)
            low = mid + 1;
        else
            return mid;
    }
        return -1;
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
        printf("ungetch: too many characnters\n");
    else
        buf[bufp++] = c;
}

int getword(char *word, int lim)
{
    int c, d; 
    int getch(void);
    void ungetch(int);
    int in_comment(void);
    char *w = word;
    
    while(isspace(c = getch()) && c != '\n')
        ;
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
