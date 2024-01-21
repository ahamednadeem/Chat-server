/* program entab that replaces strings of blanks by the minimum number
of tabs and blanks to achieve the same spacing */


#include <stdio.h>

#define SPACE_TO_TAB 8  //default spacing

int main()
{
  int space = 0, i;
  int character;

  while((character = getchar()) != EOF) 
  {
    if(character == ' ') 
    {
      space++;
    }
    else 
    {
      if(space > 0) 
      {
        for(i = 0; i < space/SPACE_TO_TAB; i++) //space must be greater than SPACE_TO_BAR for this loop to run
          putchar('\t');
        for(i = 0; i < space % SPACE_TO_TAB; i++) 
          putchar(' ');
        space = 0;
      }
      putchar(character);
    }
  }
  return 0;
}
