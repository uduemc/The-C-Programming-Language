#include <stdio.h>
#include <ctype.h>
double atofs(char s[]);
int main()
{
	printf("%f\n",atofs("177.23456"));
	printf("%f\n",atofs("123.45e-6"));
	return 0;
}

double atofs(char s[])
{
	double val, power;
	int i, sign, eval, tmp, ta, j;
	
	for(i=0; isspace(s[i]);i++)
		;
	sign = (s[i] == '-')? -1: 1;
	if(s[i] == '+' || s[i] == '-')
		i++;
	
	for(val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	
	if(s[i] == '.')
		i++;
	
	for(power = 1.0; isdigit(s[i]); i++){
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	
	eval = 1;
	if(s[i++] == 'e'){
		if(s[i++] == '-'){
			ta = -10;
		}else{
			ta = 10;
		}
		tmp = s[i++] - '0';
		for(j = 0;j<tmp; j++){
			eval *= ta;
		}
	}
	
	
	return sign * val / power / eval;
}