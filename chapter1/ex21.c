#include <stdio.h>

#define SPACE_TO_TAB 8

int main()
{
  int space = 0, i;
  int character;

  while((character = getchar()) !=EOF) 
  {
    if(character == ' ') 
    {
      space++;
    }
    else 
    {
      if(space > 0) 
      {
        for(i = 0; i < space/SPACE_TO_TAB; i++) 
	{
          putchar('\t');
        }
        for(i = 0; i< space % SPACE_TO_TAB; i++) 
	{
          putchar(' ');
        }
        space = 0;
      }
      putchar(character);
    }
  }
  return 0;
}
