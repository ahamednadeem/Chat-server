/* test the word count program */

#include <stdio.h>

#define IN 1
#define OUT 0

void main()
{
int c, newline, new_word, new_character, state;
state = OUT;                                       // this represents whether we are currently inside the word or not 
newline = new_word = new_character = 0;
while ((c = getchar()) != EOF)
{
	++new_character;			     //counting the no of characters
        if (c == '\n')
        	++newline;                         //counting the no of lines
	if (c == ' ' || c == '\n' || c =='\t')
		state = OUT;
	else if (state == OUT) 
	{
		state = IN;
		++new_word;                       //counting the no of words
        }
}
	printf("%d %d %d\n", newline, new_word, new_character);
}

