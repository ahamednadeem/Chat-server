/* Write a function htoi(s) , which converts a string of hexadecimal digits
 into its equivalent integer value. The allowable digits are 0
through 9 , a through f , and A through F . */

#include <stdio.h>
#include<stdlib.h>
#define MAXLINE 10


int htoi(const char s[]);
void _getline(char line[], int lim);

int main() 
{
    	int len;
    	char line[MAXLINE];
    	int value;

    	_getline(line, MAXLINE);
    	
    	printf("%s\n", line);
    	
    	value = htoi(line);
    	printf("The value is %d \n", value);

    return 0;
}

void _getline(char line[], int lim)   //get input from the user
{
    int character, i;

    for (i = 0; i < lim  && (character = getchar()) != EOF && character != '\n'; ++i)
        line[i] = character;

    if (character == '\n') 
        line[i++] = character;

    line[i] = '\0';


}

int htoi(const char s[])    //converts string of hexadecimal digits to its integer equivalent
{
    int hexdigit, i, inhex, n;   // inhex means if it is in hexadigit
    n = 0;
    inhex = 1;

    for (i = 0; inhex == 1 && s[i] != '\n' && s[i] != '\0' ; ++i) 
    {
        if (s[i] >= '0' && s[i] <= '9')
            hexdigit = s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            hexdigit = s[i] - 'a' + 10;   // in hexadigit 'a' is 10 in integer
        else if (s[i] >= 'A' && s[i] <= 'F')
            hexdigit = s[i] - 'A' + 10;
        else
        {
            printf("Invalid input \n ");
            exit(0);
        }

        if (inhex == 1)
            n = 16 * n + hexdigit;
    }
    return n;
}
