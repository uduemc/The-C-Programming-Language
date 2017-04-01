#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 	1024
#define TABINC		4
#define SPACE 		' '
#define TAB 		'\t'

int getlines(char s[], int len);
void spaceinitbuffer(char spacebuffer[]);
int main(){
	char buffer[MAX_BUFFER];
	char spacebuffer[TABINC];
	int i,j,spe;
	spe = 0;
	spaceinitbuffer(spacebuffer);
	// 每4个空格替换一个 \t
	while(getlines(buffer,MAX_BUFFER) > 0){
		for(i = 0;buffer[i]!='\0';i++){
			if(buffer[i] == SPACE){
				spacebuffer[spe] = buffer[i];
				spe++;
				if(spe == TABINC){
					putchar('\t');
					spe = 0;
				}
			}else{
				for(j=0;spacebuffer[j]!='\0';j++){
					putchar(spacebuffer[j]);
				}
				if(j>0)
					spaceinitbuffer(spacebuffer);
				
				putchar(buffer[i]);
				if(spe != 0)
					spe = 0;
			}
		}
	}
	return 0;
}

void spaceinitbuffer(char spacebuffer[]){
	int i;
	for(i = 0; i< TABINC;i++){
		spacebuffer[i] = '\0';
	}
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