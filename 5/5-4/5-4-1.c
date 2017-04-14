#include <stdio.h>

int strends(char *, char *);

int main()
{
	char *s = "ababacdegould";
	char *t = "dls";
	char *z = "uld";
	
	printf("strends(s, t): %d\n", strends(s, t));
	printf("strends(s, z): %d\n", strends(s, z));
	return 0;
}

int strends(char *s, char *t)
{
	int slen,tlen;
	slen = tlen = 0;
	while(*(s + slen) != '\0')
		slen++;
	while(*(t + tlen) != '\0')
		tlen++;
	if(tlen > slen)
		return 0;
	s = s + slen - tlen;
	for(;*s == *t;s++,t++)
		if(*s == '\0')
			return 1;
	return 0;
}