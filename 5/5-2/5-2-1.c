#include <stdio.h>
#include <ctype.h>

int getfloat(float *);
int main()
{
	float p;
	if(getfloat(&p) > 0)
		printf("%f\n",p);
	return 0;
}

int getfloat(float *f)
{
	char c;
	int sign, d, b, n,sta;
	sta = d = b = 0;
	while(isspace((c=getchar())))
		;
	if(!isdigit(c) && c!=EOF && c!='+' && c!='-')
		return -1;
	sign = c=='-'? -1: 1;
	if(c=='+' || c=='-')
		c = getchar();
	if(!isdigit(c) && c!=EOF)
		return -1;

	do{
		if(isdigit(c)){
			if(sta == 0){
				d = 10 * d + (c-'0');
			}else{
				b = 10 * b + (c - '0');
				n = n * 10;
			}

		}else{
			if(c == '.'){
				sta = 1;
				n = 1;
			}
		}
		c=getchar();
	}while(c!=EOF && c!='\n');
	*f = ((float)b / n + (float)d) * (float)sign;
	return 1;
}
