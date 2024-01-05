#include <stdio.h>

void rcomment(int c);

void incomment(void);


int main(void) {
    int c, d;

    while ((c = getchar()) != EOF)
        rcomment(c);

    return 0;
}

void rcomment(int c) {
    int d;

    if (c == '/') {
        if ((d = getchar()) == '*')
            incomment();
        else if (d == '/') {
            putchar(c);
            rcomment(d);
        } else {
            putchar(c);
            putchar(d);
        }
    } 
    else
        putchar(c);
}

void incomment() {
    int c, d;

    c = getchar();
    d = getchar();

    while (c != '*' || d != '/') {
        c = d;
        d = getchar();
    }
}


