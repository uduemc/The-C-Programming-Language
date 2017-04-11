#include <stdio.h>

#define MAXLENGTH 1024

int getlines(char s[], int len);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main()
{
	char buffer[MAXLENGTH];
	int rposition;
	while(getlines(buffer, MAXLENGTH) > 0){
		if((rposition=strrindex(buffer, pattern)) >= 0){
			printf("rposition: %d, %s\n", rposition, buffer);
		}
	}
	return 0;
}

int getlines(char s[], int len)
{
	int i=0;
	char c;
	while(i<len-1&&(c=getchar())!=EOF&&c!='\n')
		s[i++] = c;
	if(c=='\n')
		s[i++] = '\n';
	s[i] = '\0';
	return i;
}

int strrindex(char s[], char t[])
{
	int i, j, k;
	int result = 0;
	for(i=0;s[i]!='\0';++i){
		j = i;
		k = 0;
		while(t[k]){
			if(s[j++]!=t[k++]){
				k=0;
				break;
			}
		}
		if(k!=0){
			result = i;
		}
	}
	if(result == 0)
		return -1;
	return result;
}
