#include <stdio.h>

int strlens(char s[]);
void reverse(char s[]);

int main()
{
	char s[] = "abcdefg";
	printf("s[]: %s\n",s);
	reverse(s);
	printf("reverse(s): %s\n",s);
	return 0;
}

int strlens(char s[])
{
	int i = 0;
	while(s[i++])
		;
	return i-1;
}

void reverse(char s[])
{
	static int i,j;
	char c;
	if(!j && strlens(s) > 0){
		j = strlens(s) - 1;
		i = 0;
	}
	if(i<j){
		c = s[j];
		s[j] = s[i];
		s[i] = c;
		i++;
		j--;
		reverse(s);
	}
}
