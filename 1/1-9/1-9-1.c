#include <stdio.h>
int main(){
	// 编写一个将输入复制到输出的程序，并将其中连续的多个空格用一个空格代替
	char c;
	int num = 0;
	while((c = getchar()) != EOF){
		if(num == 0){
			if(c == ' '){
				num = 1;
			}
		}else{
			if(c == ' '){
				continue;
			}else{
				num = 0;
			}
		}
		printf("%c",c);
	}
	return 0;
}
