/* routine of the longest-line program */

#include <stdio.h>
#define MAX 10


int get_line(char arr[], int lim);
void copy(char to[], const char from[]);

int main() 
{
    int len, max;
    char line[MAX + 1];
    char longest[MAX + 1];

    max = 0;
    while ((len = get_line(line, MAX)) > 0) 
    {

        if (len > max) 
        {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) 
        printf("Maximum length = %i, string with maximum length = %s\n", max, longest);
    else
    	printf("Enter Valid input");
    			
    return 0;
}

// Get input lines from the user
int get_line(char arr[], int lim) 
{
    int character, i;
    for (i = 0; i < lim - 1 && (character = getchar()) != EOF && character != '\n'; ++i) 
        arr[i] = character;
    if (character == '\n') 
        arr[i++] = character;
    arr[i] = '\0';
    return i;
}

// Copy the input to a character array if it's length is longer than maximum length
void copy(char to[], const char from[]) 
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}
