#include <stdio.h>

char clower(char c)
{
	return c>='A' && c<='Z' ? c + 'a' - 'A':c ;
}

int main()
{
	printf("%c\n",clower('C'));
	printf("%c\n",clower('B'));
	printf("%c\n",clower('b'));
	return 0;
}