#include <stdio.h>
int main(){
	// 编写一个程序，打印长度大于80个字符的所有输入行
	// 自己的写法
	// 然而这种方式并不理想!
	int c,i;
	int len = 0;
	int buffer[81] = {0};
	int isPrint = 0;
	
	while((c=getchar()) != EOF){
		if(c == '\n'){
			len = 0;
			isPrint = 0;
			
		}else{
			len++;
		}
		// 需要存储前80个字符
		if(len > 80){
			if(isPrint == 0){
				for(i=0;i<81;i++){
					putchar(buffer[i]);
				}
				isPrint= 1;
			}
			putchar(c);
		}else{
			buffer[len] = c;
		}
	}
	return 0;
}