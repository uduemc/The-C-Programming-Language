#include <stdio.h>
#define MAX_LINE 1024

int getlines(char line[], int lineNum);

void reverse(char line[]);

int main(){
	int i;
	char line[MAX_LINE];
	
	for(i=0;i<MAX_LINE;i++)
		line[i] = '\0';
	
	while(getlines(line, MAX_LINE) > 0){
		// ·´×ª
		reverse(line);
		// print
		printf("\nline: %s",line);
	}
	printf("\n");
	return 0;
}

int getlines(char line[], int lineNum){
	int c;
	int i;
	for(i=0;i<lineNum-1 && (c=getchar())!=EOF && c != '\n';i++){
		line[i] = c;
	}
	if(i > 0 && c == '\n'){
		line[i++] = c;
	}
	return i;
}

void reverse(char line[]){
	int i,len,tmp;
	for(i = 0;i<MAX_LINE ;i++){
		if(line[i] == '\0'){
			len = i- 1;
			break;
		}
	}
	for(i = 0;i<=len;i++){
		tmp = line[i];
		line[i] = line[len];
		line[len] = tmp;
		len--;
	}
}