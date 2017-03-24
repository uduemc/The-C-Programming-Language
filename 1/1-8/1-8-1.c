#include <stdio.h>
int main(){
	int c;
	unsigned int sn = 0;	// 空格
	unsigned int tn = 0;	// 制表符
	unsigned int nn = 0;	// 回车
	while((c = getchar()) != EOF){
		if(c==32)
			sn++;
		if(c==9)
			tn++;
		if(c==10)
			nn++;
	}
	printf("%d \n",sn);
	printf("%d \n",tn);
	printf("%d \n",nn);
	return 0;
}
