#include <stdio.h>
#define MAXLENG 100

int getlines(char s[], int len);

int main()
{
	return 0;
}

int getlines(char s[], int len)
{
	char c;
	int i;
	for(i = 0; i<len -1 && (c=getchar())!=EOF && c!='\n';i++){
		s[i] = c;
	}
	if(c=='\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}