#include <stdio.h>
int main(){
	char c;
	unsigned int sn = 0;	// 空格
	unsigned int tn = 0;	// 制表符
	unsigned int nn = 0;	// 回车
	while((c = getchar()) != EOF){
		if(c==' ')
			sn++;
		if(c=='\t')
			tn++;
		if(c=='\n')
			nn++;
	}
	printf("%d \n",sn);
	printf("%d \n",tn);
	printf("%d \n",nn);
	return 0;
}
