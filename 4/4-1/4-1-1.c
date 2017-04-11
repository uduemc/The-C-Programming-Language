#include <stdio.h>

#define MAXLENGTH 1024

int getlines(char s[], int len);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main()
{
	char buffer[MAXLENGTH];
	int position;
	while(getlines(buffer, MAXLENGTH) > 0){
		if((position=strindex(buffer, pattern)) >= 0){
			printf("position: %d, %s\n", position, buffer);
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

int strindex(char s[], char t[])
{
	int i, j, k;
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
			return i;
		}
	}
	return -1;
}
