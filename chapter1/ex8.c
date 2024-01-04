#include<stdio.h>
void main()
{
	int c;
	int blank_counts;
	int tabs_counts;
	int newline_counts;
	while((c = getchar()) != EOF)
	{
		
		if (c == ' ')
		{
			blank_counts++;
		}
		else if (c == '\t')
		{
			tabs_counts++;
		}
		else if (c == '\n')
		{
			newline_counts++;
		}
	}
	printf("Blank Space : %d\n", blank_counts);
	printf("Tabs : %d\n", tabs_counts);
	printf("Newline :%d\n", newline_counts);
}
		
