#include <stdio.h>

int getlines(char *, int len);

int main()
{
	char buffer[1024];
	while( getlines(buffer, 1024) > 0 )
		printf("%s",buffer);
	return 0;
}

int getlines(char *s, int len)
{
	char c;
	int i=0;
	while(i < len - 1 && (c=getchar()) != EOF && c!='\n'){
		*s++ = c;
		i++;
	}
		
	if(c == '\n'){
		*s++ = '\n';
		i++;
	}
	*s = '\0';
	return i;
}