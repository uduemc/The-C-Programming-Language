#include <stdio.h>
int main(){
	// 编写一个将输入复制到输出的程序，
	// 并将其中的制表符替换成 \t ，把回退符替换成 \b，把反斜杠替换为\\
	// 这样可以将制表符和回退符以可见的方式显示出来
	char c;
	
	while((c=getchar())!=EOF){
		if(c=='\t'){
			printf("\\t");
			continue;
		}
		if(c=='\b'){
			printf("\\b");
			continue;
		}
		if(c=='\\'){
			printf("\\\\");
			continue;
		}
		printf("%c",c);
	}
	return 0;
}