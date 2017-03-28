#include <stdio.h>
#define MAXLINE 20

int getlines(char line[], int maxline);
void copy(char to[], char from[]);

int main(){
	// 修改打印最长文本行的程序的主程序main，
	// 使之可以打印任意长度的输入行长度
	// 并尽可能多地打印文本
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];
	
	max = 0;
	while((len = getlines(line,MAXLINE)) > 0){
		printf("%d: %s \n",len,line);
		if(len > max){
			max = len;
			copy(longest, line);
		}
	}
	if(max > 0){
		printf("Longest is %d characters: \n%s",max,longest);
	}
	printf("\n");
	return 0;
}

int getlines(char s[], int lim){
	int c, i, j;
	for(i=0,j=0; (c=getchar()) != EOF && c!='\n';i++){
		if(i < lim -1){
			s[j++] = c;
		}
	}
	if(c == '\n'){
		if(i < lim -1){
			s[j++] = c;
		}
		i++;
	}
	s[j] = '\0';
	return i;
}

void copy(char to[], char from[]){
	int i = 0;
	while((to[i] = from[i]) != '\0')
		i++;
}