#include <stdio.h>
int main(){
	int c;
	unsigned int sn = 0;	// �ո�
	unsigned int tn = 0;	// �Ʊ��
	unsigned int nn = 0;	// �س�
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
