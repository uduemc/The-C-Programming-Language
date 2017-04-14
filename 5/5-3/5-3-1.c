#include <stdio.h>

void strcats(char *s, char *t);

int main()
{
	char s[20] = "abc";
	char *t = "def";
	printf("s[20]: %s\n", s);
	printf("*t: %s\n", t);
	strcats(s, t);
	printf("s[20]: %s\n", s);
	return 0;
}

void strcats(char *s, char *t)
{
	while(*s++ != '\0')
		;
	s--;
	while(*s++ = *t++)
		;
}

