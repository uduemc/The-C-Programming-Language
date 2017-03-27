#include <stdio.h>
#define MAXLENG 255
#define OUT 0
#define IN 1
int main(){
	char c;
	char charArr[MAXLENG];
	int i,j,maxLen;
	maxLen = 0;
	for(i=0;i<MAXLENG;i++)
		charArr[i] = 0;
	
	while((c=getchar()) != EOF){
		charArr[c]++;
	}
	printf("\n");
	printf("**Transverse**\n");
	for(i=0;i<=MAXLENG;i++){
		if(charArr[i] == 0)
			continue;
		if((i>='0' && i<='9') || (i>='A' && i<='Z') || (i>='a' && i<='z')){
			printf("%c: ",i);
			for(j=0;j<charArr[i];j++){
				printf("*");
			}
			printf("\n");
		}
	}
	printf("\n");
	printf("**Portrait**\n");
	for(i=0;i<=MAXLENG;i++){
		if(maxLen<charArr[i])
			maxLen = charArr[i];
	}
	for(i=maxLen;i>0;i--){
		for(j=0;j<=MAXLENG;j++){
			if(charArr[j] == 0)
				continue;
			if((j>='0' && j<='9') || (j>='A' && j<='Z') || (j>='a' && j<='z')){
				if(charArr[j] >= i){
					printf(" * ");
				}else{
					printf("   ");
				}
			}
		}
		printf("\n");
	}
	for(i=0;i<=MAXLENG;i++){
		if(charArr[i] == 0)
			continue;
		if((i>='0' && i<='9') || (i>='A' && i<='Z') || (i>='a' && i<='z')){
		printf(" %c ",i);
		}
	}
	printf("\n");
	return 0;
}