/* itoa does not handle the largest negative number, modify the code */


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
    number = -2147483648; //maximum negative integer 
    itoa(number, str);
    printf("String : %s\n", str);
    return 0;
}

void itoa(int n, char s[])   // convertes integer to string
{
    int i, sign;
    sign = n; 
    i = 0;
    do 
    {
        s[i++] = absolute(n % 10) + '0';   // '0' is used to convert integer to string
    } 
    while ((n /= 10) != 0);

    if (sign < 0)
        s[i++] = '-';  //add the - sign atlast and then reverse it

    s[i] = '\0';

    reverse(s);
}

void reverse(char s[])   // reverses the input array
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}

int absolute(int k)  // take absolute of the input hence negative numbers won't affect the output
{
	k = (k > 0 ? k : -k);
	return k;
}
