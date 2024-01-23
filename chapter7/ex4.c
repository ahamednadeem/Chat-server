/* private version of scanf analogous to minprintf */

#include<stdio.h>
#include<stdarg.h>

void minscanf(char *fmt, ...);

int main(void)
{
	int i;
	minscanf("%d", &i);
	printf("minscanf input: %d\n", i);
	
	float f;
	minscanf("%f", &f);
	printf("minscanf input: %f\n", f);
	
	return 0;
}

void minscanf(char *fmt, ...)
{
	va_list ap;  // declare a variable that will point to each arg in turn 
	int *ival;
	float *dval;
	char *p;
	
	va_start(ap, fmt); // make ap point to 1st unnamed arg 
	
	for(p = fmt; *p; p++)
	{
		if(*p != '%')
			continue;
		
		switch(*++p)
		{
			case 'd':
				ival = va_arg(ap, int *);
				char *d = "98";
				sscanf(d, "%d", ival);
				break;
			case 'f':
				dval = va_arg(ap, float *);
				char *f = "98.23";
				sscanf(f, "%f", dval);
				break;
			default:
				putchar(*p);
				break;
		}
	}
	va_end(ap);   //cleans up when done
}
			
		
	
	
	
