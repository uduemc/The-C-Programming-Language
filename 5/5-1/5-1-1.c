#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int getint(int *p);

int main()
{
	int p;
	if(getint(&p) > 0)
		printf("%d\n", p);
    getchar();
	return 0;
}

int getint(int *p)
{
	int c;
	int sign;
	while(isspace((c=getchar())))
		;
	if(!isdigit(c) && c!=EOF && c!='+' && c!='-'){
		putchar(c);
		return 0;
	}
	sign = c=='-'? -1: 1;
	if(c == '+' || c == '-')
		c = getchar();
	if(!isdigit(c) && c!=EOF){
		putchar(c);
		return 0;
	}
	for(*p=0;isdigit(c) && c!=EOF;c=getchar())
		*p = 10 * *p + ( c - '0');
	*p = *p * sign;
	return c;
}