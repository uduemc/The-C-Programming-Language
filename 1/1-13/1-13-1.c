#include <stdio.h>
#define MAXWORD 50
#define OUT 0
#define IN 1
int main(){
	int c; // 获取到的char
	int status; // 当前的状态.
	int word[MAXWORD];
	int i,j;
	int worldLen,maxLeng;
	int wordNum = 0;
	
	for(i = 0 ;i<MAXWORD;i++)
		word[i] = 0;
	
	// 默认在外部
	status = OUT;
	while((c=getchar()) != EOF){
		if(wordNum > MAXWORD - 1){
			break;
		}
		if(c==' ' || c=='\n' || c=='\t'){
			if(status == IN){
				status = OUT;
				word[wordNum] = worldLen;
				wordNum++;
				printf("\n");
			}
			continue;
		}else{
			if(status == OUT){
				status = IN;
				worldLen = 0;
				printf("%2d: ",wordNum+1);
			}
			worldLen++;
			printf("%c",c);
		}
	}
	printf("\n");
	printf("**Transverse**\n");
	for(i=0;i<wordNum;i++){
		printf("%2d:\t",i+1);
		for(j=0;j<word[i];j++){
			printf("*");
		}
		printf("\n");
	}
	printf("\n");
	printf("**Portrait**\n");
	maxLeng = 0;
	for(i=0;i<wordNum;i++){
		if(maxLeng<word[i]){
			maxLeng = word[i];
		}
	}
	// 准备循环 maxLeng 次
	for(i=maxLeng;i>0;i--){
		for(j=0;j<wordNum;j++){
			if(i<=word[j]){
				printf(" * ");
			}else{
				printf("   ");
			}
		}
		printf("\n");
	}
	for(i=0;i<wordNum;i++){
		printf("%2d ",i+1);
	}
	printf("\n");
	return 0;
}