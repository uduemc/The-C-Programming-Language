#include <stdio.h>
int main(){
	char c;
	unsigned int sn = 0;	// �ո�
	unsigned int tn = 0;	// �Ʊ��
	unsigned int nn = 0;	// �س�
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
