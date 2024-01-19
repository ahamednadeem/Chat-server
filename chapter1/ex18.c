#include <stdio.h>

#define MAXLINE 10

int getlines(char line[], int lim);
int remove_trail(char rline[]);

int main() {
    int len;
    char line[MAXLINE];

    while ((len = getlines(line, MAXLINE)) > 0)
        if (remove_trail(line) > 0)
            printf("%s", line);

    return 0;
}

int getlines(char line[], int lim) {
    int i, characters;

    for (i = 0; i < lim - 1 && (characters = getchar()) != EOF && characters != '\n'; ++i)
        line[i] = characters;
    if (characters == '\n') {
        line[i] = characters;
        ++i;
    }
    line[i] = '\0';

    return i;
}

int remove_trail(char rline[]) {
    int i;

    for (i = 0; rline[i] != '\n'; ++i);
    	--i; 

    for (i > 0; ((rline[i] == ' ') || (rline[i] == '\t')); --i); 

    if (i >= 0) 
    {
        ++i;
        rline[i] = '\n';
        ++i;
        rline[i] = '\0';
    }
    return i;
}
