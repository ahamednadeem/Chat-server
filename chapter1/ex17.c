#include <stdio.h>

#define MAXLINE 1000
#define character_length 80

int get_line(char array[], int limit);
int main() 
{
    int len;
    char line[MAXLINE];
    while ((len = get_line(line, MAXLINE)) > 0) 
    {
	 if (len > character_length)
	 {	
	 	printf("%s", line);
	 }

    }

    return 0;
}

int get_line(char array[], int limit) 
{
    int characters, i;
    for (i = 0; i < limit - 1 && (characters = getchar()) != EOF && characters != '\n'; ++i) 
    {
        array[i] = characters;
    }
    if (characters == '\n') 
    {
        array[i] = characters;
        ++i;
    } 
    array[i] = '\0';
    return i; //i is the length of the characters
}
