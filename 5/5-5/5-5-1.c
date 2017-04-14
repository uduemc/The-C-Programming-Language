#include <stdio.h>

void strncpys(char *, char *, int n);
void strncats(char *, char *, int n);
int strncmps(char *, char *, int n);

int main()
{
	char s[20];
	char s1[20] = "xyz";
	char s2[20] = "abcxyz";
	char *t = "abcdefg";
	
	strncpys(s, t, 3);
	printf("strncpys(s, t, 3): %s\n", s);
	strncats(s1, t, 3);
	printf("strncats(s1, t, 3): %s\n", s1);
	printf("strncmps(s2, t, 3): %d\n", strncmps(s2, t, 3));
	return 0;
}

int strncmps(char *s, char *t, int n)
{
	int i;
	for(i = 0;*s == *t; s++,t++,i++){
		if(*s == '\0' || i >= (n - 1))
			return 0;
	}
	return *s - *t;
}

void strncats(char *s, char *t, int n)
{
	int i = 0;
	while(*s++ != '\0')
		;
	s--;
	while((*s++ = *t++) && i++ < n-1)
		;
	if(*s != '\0')
		*s = '\0';
}

void strncpys(char *s, char *t, int n)
{
	int i = 0;
	while((*s++ = *t++) && i++ < n-1)
		;
	if(*s != '\0')
		*s = '\0';
}