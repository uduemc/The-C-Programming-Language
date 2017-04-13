#include <stdio.h>

char buf[100];
int bufp = 0;

char getch(void)
{
	return bufp > 0 && buf[bufp] != EOF? buf[--bufp]: getchar();
}

void ungetch(char c)
{
	if (bufp >= 100)
		printf("ungetch: too many character\n");
	else{
		if(c != EOF){
			buf[bufp++] = c;
		}
	}
}

int main()
{
	ungetch(EOF);
	printf("%c\n",getch());
	return 0;
}