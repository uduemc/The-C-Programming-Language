#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 	1024
#define TABINC		4
#define SPACE 		' '
#define TAB 		'\t'

int getlines(char s[], int len);

int main(){
	char buffer[MAX_BUFFER];
	int i,j;
	
	while(getlines(buffer,MAX_BUFFER) > 0){
		for(i = 0;buffer[i]!='\0';i++){
			if(buffer[i] == TAB){
				for(j=0;j<TABINC;j++){
					putchar(SPACE);
				}
			}else{
				putchar(buffer[i]);
			}
		}
	}
	return 0;
}

int getlines(char s[], int len){
	char c;
	int i;
	
	for(i=0;i<len-1 && (c=getchar())!=EOF && c!='\n';i++){
		s[i] = c;
	}
	
	if(c=='\n'){
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}