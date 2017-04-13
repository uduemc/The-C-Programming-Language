#include <stdio.h>

#define swap(t, x, y) do{t z;z=x;x=y;y=z;}while(0)

int main()
{
	char x = 'a', y = 'z';
	swap(char, x, y);
	printf("x = %c\ny = %c\n",x ,y);
	return 0;
}