#include <stdio.h>
#define MINLENGTH 81
int readbuff(char *buffer){
	int i = 0;
	int c;
	while(i<MINLENGTH){
		c = getchar();
		if(c == EOF) return -1;
		if(c == '\n') return 0;
		buffer[i++] = c;
	}
	// 超过80
	return 1;
}
int copyline(char *buffer){
	int i;
	int c;
	int status = 1;
	for(i = 0; i< MINLENGTH ; i++){
		putchar(buffer[i]);
	}
	while(status == 1){
		c = getchar();
		if(c == EOF)
			status = -1;
		else if( c== '\n')
			status = 0;
		else
			putchar(c);
	}
	return status;
}
int main(){
	// 编写一个程序，打印长度大于80个字符的所有输入行
	// 答案的写法如下
	char buffer[MINLENGTH];
	int status = 0;
	while(status != -1){
		status = readbuff(buffer);
		if(status == 1)
			status = copyline(buffer);
	}
	return 0;
}