#include <stdio.h>
#define MAXLINE 80


int htoi(const char s[]);
int _getline(char line[], int lim);


int main() 
{
    int len;
    char line[MAXLINE];
    int value;

    len = _getline(line, MAXLINE);
    value = htoi(line);

    printf("The value is %d", value);

    return 0;
}

int _getline(char line[], int lim) {
    int character, i;

    for (i = 0; i < lim - 1 && (character = getchar()) != EOF && character != '\n'; ++i)
        line[i] = character;

    if (character == '\n') 
    {
        line[i] = character;
        ++i;
    }
    line[i] = '\0';

    return i;
}

int htoi(const char s[]) 
{
    int hexdigit, i, inhex, n;
    n = 0;
    inhex = 1;

    for (i = 0; inhex == 1; ++i) 
    {
        if (s[i] >= '0' && s[i] <= '9')
            hexdigit = s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            hexdigit = s[i] - 'a' + 10;
        else if (s[i] >= 'A' && s[i] <= 'F')
            hexdigit = s[i] - 'A' + 10;
        else
            inhex = 0;

        if (inhex == 1)
            n = 16 * n + hexdigit;
    }
    return n;
}
