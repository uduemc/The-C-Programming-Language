#include <stdio.h>

void itoas(int n, char s[], int *j);
void reverse(char s[]);

int main()
{
	char buffer[20];
	int num = 0;
	itoas(1234,buffer,&num);
	printf("%d itoa: %s\n",1234, buffer);
	num = 0;
	itoas(-1234,buffer,&num);
	printf("%d itoa: %s\n",-1234, buffer);
	return 0;
}

void itoas(int n, char s[], int *j){
	int sign,tmp;
	tmp = *j;
	if((sign = n) < 0){
		n = -n;
	}
	if(n > 0){
		s[(*j)++] = n % 10 + '0';
		n = n / 10;
		itoas(n, s, j);
	}
	if(tmp == 0 ){
		if(sign < 0)
			s[(*j)++] = '-';
		s[(*j)] = '\0';
		reverse(s);
	}
}

void reverse(char s[])
{
	int i,j,strl;
	char c;
	
	i = 0;
	while(s[i++]!='\0')
		;
	strl = i - 2;
	for (i = 0,j = strl; i< j; i++ , j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
	
}