#include <stdio.h>
#define OUT 0
#define IN 1
int main(){
	// ���ʼ���
	int c,nl,nw,nc,state;
	state = OUT;
	nl = nw = nc = 0;
	while((c = getchar()) != EOF){
		nc++;
		if(c == '\n'){
			nl++;
		}
		if(c == ' ' || c == '\n' || c == '\t'){	// ֻ������ �ո񡢻��С��Ʊ��
			state = OUT;
		}else if(state == OUT){
			state = IN;
			nw++;
		}
	}
	printf("nc:%d\tnl:%d\tnw:%d",nc, nl, nw);
	return 0;
}