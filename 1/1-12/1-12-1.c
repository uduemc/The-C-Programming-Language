#include <stdio.h>
#define OUT 0
#define IN 1
int main(){
	int c,status;
	while((c = getchar()) != EOF){
		if(c==' ' || c=='\n' || c=='\t'){
			if(status == IN){
				printf("\n");
			}
			status = OUT;
		}else{
			if(status == OUT){
				status = IN;
			}
			printf("%c",c);
		}
	}
	return 0;
}