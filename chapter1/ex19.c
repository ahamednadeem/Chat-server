#include<stdio.h>

#define MAXLINE 1000

int getlines(char line[], int lim);
void reverse_string(char rev[]);

int main() 
{
    int len;
    char line[MAXLINE];


    while ((len = getlines(line, MAXLINE)) > 0)
    {		reverse_string(line);
       	printf("%s", line);
    }

    return 0;
}

int getlines(char line[], int lim) 
{
    int i, characters;

    for (i = 0; i < lim - 1 && (characters = getchar()) != EOF && characters != '\n'; ++i)
        line[i] = characters;
        
    if (characters == '\n') 
    {
        line[i] = characters;
        ++i;
    }
    
    line[i] = '\0';
    return i;
}

void reverse_string(char rev[]) {
    int i, j;
    char temp;

    for (i = 0; rev[i] != '\0'; ++i);
    	--i;

    if (rev[i] == '\n')
        --i;

    j = 0;

    while (j < i) {
        temp = rev[j];
        rev[j] = rev[i];
        rev[i] = temp;
        --i;
        ++j;
    }
}
	
	
