#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int day_of_year(int year, int month, int day)
{
    int i, leap;
    if(month < 1 || month > 12)
        return -1;

    if(day < 1 || day > 31)
        return -1;
    leap = ((year%4==0 && year%100!=0) || (year%400==0));
    if(day > daytab[leap][month])
        return -1;
    for(i=1;i<month;i++)
        day += daytab[leap][i];
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    if(yearday < 1 || yearday > 366){
        printf("yearday not greater than 366");
        return;
    }
    leap = ((year%4==0 && year%100!=0) || (year%400==0));
    for (i = 1; yearday > daytab[leap][i] && i < 13; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

int main()
{
    int month,day;
    printf("day_of_year(2017, 4, 17): %d\n", day_of_year(2017, 4, 17));
    month_day(2017, 255, &month, &day);
    printf("month_day(2017, 255, &month, &day): month: %d, day: %d\n", month, day);
	return 0;
}
