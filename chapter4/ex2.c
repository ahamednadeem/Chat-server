#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100

double _atof(char s[]);
void mgetline(char line[], int lim);
int power(int base, int exp);
double val, powi;
int sign, i, esign, expi;
    

int main() 
{
    char str[MAXLINE];
    double num;
    mgetline(str, MAXLINE);
    num = _atof(str);
    printf("%f", num);

    return 0;
}

double _atof(char s[]) //converts a string into a floating point numerical representation
{
    

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if (s[i] == '.')
        i++;

    for (powi = 1.0; isdigit(s[i]); i++) 
    {
        val = 10.0 * val + (s[i] - '0');
        powi *= 10.0;                              
    }

    if (s[i] == 'e' || s[i] == 'E')
        i++;
    if (s[i] == '+' || s[i] == '-')
     {
        esign = s[i];
        i++;
     }

    for (expi = 0; isdigit(s[i]); i++)
        expi = 10.0 * expi + (s[i] - '0');

    if (esign == '-')
        return sign * (val / powi) / power(10, expi);
    else

        return sign * (val / powi) * power(10, expi);
}

void mgetline(char line[], int lim) //get input from the user
{
    int i, c;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n')
        line[i++] = c;
        
    line[i] = '\0';
}

int power(int base, int expi) //calculate the power of e
{
    int power;
    power = 1;
    while (expi > 0)
    {
    	--expi;
        power *= base;
    }

    return power;
}
