#include <stdio.h>

int getlines(char s[], int len);

int main()
{
	char buffer[1024];
	while(getlines(buffer, 1024) > 0){
		printf("%s",buffer);
	}
	return 0;
}

int getlines(char s[], int len)
{
	char c;
	int i;
	
	i = 0;
	while(i < len - 1){
		if((c=getchar()) == EOF)
			break;
		
		if(c == '\n')
			break;
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	
	return i;
}