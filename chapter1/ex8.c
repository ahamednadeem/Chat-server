/* program to count blanks, tabs, and newlines. */

#include<stdio.h>
void main()
{
	int c;
	int blank_counts = 0;
	int tabs_counts = 0;
	int newline_counts = 0;
	while((c = getchar()) != EOF)
	{
		if (c == ' ')
			blank_counts++;
		else if (c == '\t')
			tabs_counts++;
		else if (c == '\n')
			newline_counts++;
	}
	printf("Blank sapce: %d Tab Counts: %d Newlines: %d\n", blank_counts, tabs_counts, newline_counts);
}


