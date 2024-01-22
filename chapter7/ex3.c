/* minprintf to handle more of the other facilities of printf .
have handled octal, hexa */


#include <stdarg.h>
#include <stdio.h>

void minprintf(char *fmt, ...);

int main(void) {
    char *a = "Ahamed Nadeem\n";
    minprintf("%s", a);
    
    int i = 198;
    minprintf("%d\n", i);
    
    int b = 011;
    minprintf("b in octal: %o, and in decimal: %d\n", b, b);
    
    int h = 10;
    minprintf("h in hex: %x, and in decimal: %d\n", h, h);
    
    return 0;
}

void minprintf(char *fmt, ...) 
{
    va_list ap; // declare a variable that will point to each arg in turn 
    char *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt); // make ap point to 1st unnamed arg 

    for (p = fmt; *p; p++) {
        if (*p != '%') 
        {
            putchar(*p);
            continue;    //terminate the current iteration
        }

        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;
            case 'o':                   //octal to decimal
                ival = va_arg(ap, int);
                printf("%o", ival);
                break;
            case 'x':                   //hexa to decimal
                ival = va_arg(ap, int);
                printf("%x", ival);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap); // clean up when done 
}
