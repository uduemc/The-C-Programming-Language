#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itoa(int n, char s[], int b);
void reverse(char s[]);

int main()
{
	char buffer[10];
	int i;
	
	for(i = 2; i<=20; i++){
		itoa(255, buffer, i);
		printf("Decimal 255 in base %-2d: %s\n", i, buffer);
	}
	return 0;
}

void itoa(int n, char s[], int b)
{
	static char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i, sign;
	
	if(b < 2 || b > 36){
		fprintf(stderr, "EX3_5: Cannot support base %d\n", b);
		exit(EXIT_FAILURE);
	}
	
	if((sign = n) < 0)
		n=-n;
	
	i = 0;
	do{
		s[i++] = abs(n%10) + '0';
	}while(n /= 10);
	
	if(sign < 0)
		s[i++] = '-';
	
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]){
	int c, i, j;
	for(i = 0, j = strlen(s) - 1; i < j; i++,j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}