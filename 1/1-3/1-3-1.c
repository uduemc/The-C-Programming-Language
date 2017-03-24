#include <stdio.h>

main(){
	printf("温度转换程序\n");
	float fahr, celsius;
	float lower, upper, step;
	lower = 0.0;
	upper = 300.0;
	step = 20.0;
	fahr = lower;
	while(fahr <= upper){
		celsius = 5*(fahr -32 )/9;
		printf("%3.0f\t%6.1f\n",fahr, celsius);
		fahr = fahr + step;
	}
	return 0;
}