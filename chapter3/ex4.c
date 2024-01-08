#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

void itoa(int n, char s[]);
void reverse(char s[]);
int absolute(int k);

int main() 
{
    int number;
    char str[MAXLINE];
    number = -2147483648;
    itoa(number, str);
    printf("String : %s", str);
    return 0;
}

void itoa(int n, char s[]) 
{
    int i, sign;
    sign = n;
    i = 0;
    do 
    {
        s[i++] = absolute(n % 10) + '0';
    } 
    while ((n /= 10) != 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';

    reverse(s);
}

void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}

int absolute(int k)
{
	k = (k > 0 ? k : -k);
	return k;
}
