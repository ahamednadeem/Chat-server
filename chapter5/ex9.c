/* Rewrite the routines day_of_year and month_day with pointers instead of
indexing. */

#include<stdio.h>

static char daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
int month_day(int year, int yearday, int *month, int *day);

void main() 
{
    int yearday, month, day;
    yearday = day_of_year(2006, 9, 30);
    if (yearday < 0)
    	printf("Invalid Input\n");
    else
    	printf("%d\n", yearday);
    
    int res = month_day(1978, 123,  &month, &day);
    if (res)
    	printf("Month: %d, Day: %d\n", month, day);
    else
    printf("Invalid Input");
}


/* day of year from month & day */

int day_of_year(int year, int month, int day) 
{
    int leap;
    char *p;
    
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > daytab[leap][month])  //condition to check for errors
        return -1;
    p = daytab[leap];
        
    while(--month)
    	day += *++p;  
    return day;
    	
}

/* month,day from day of year */

int month_day(int year, int yearday, int *month, int *day) 
{
    int leap;
    char *p;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if (year < 1 || yearday < 1 || yearday > (leap ? 366 : 365)) //condition to check for errors
        return 0;

    p = daytab[leap];
    while(yearday > *++p)	
    	yearday -= *p;
    
    *month = p - *(daytab + leap);
    *day = yearday;
    
    return 1;
}
