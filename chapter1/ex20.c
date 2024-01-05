#include<stdio.h>

#define TAB 8

int main() {
int character, count = 0, space = 0;
while((character = getchar()) != EOF) 
{

    if(character == '\t') 
    {
        space = (TAB - (count % TAB));
        while(space > 0)
        {
            putchar('@');
            count++;
            space--;
        }
    }
    else
    {
        putchar(character);
        ++count;
    }

    if(character == '\n')
        count = 0;
}
return 0;
}




