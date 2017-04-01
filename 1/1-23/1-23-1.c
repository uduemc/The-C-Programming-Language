#include <stdio.h>

#define MAX_LENGTH 10240

int getlines(char s[], int len);	// 获取输入的字符
int printCode(char s[], int len);	// 打印去除注释的代码
int main()
{
	// 测试定义一个字符串
	// Double quotation marks
	char *str = "\\大风起兮云飞扬, // 运维机房吃香肠";
	char buffer[MAX_LENGTH];
	while(getlines(buffer,MAX_LENGTH) > 0){
		printCode(buffer,MAX_LENGTH);
	}
	return 0;
}

/**
 * 过滤需要提出的字符
 * isn 单行注释
 * isnn 多行注释
 */
int printCode(char s[], int len)
{
	int i;
	int isn;
	int issn;
	int isdqm;
	int issqm;
	isdqm = isn = issn = 0;
	for(i = 0;s[i]!='\0';i++){
		
		if(isdqm == 0 && s[i] == '\''){
			if(issqm == 0){
				issqm = 1;
			}else{
				issqm = 0;
			}
		}
		
		if(s[i] == '"'&& issqm == 0 && isn == 0 && issn == 0){
			if(isdqm == 0){
				isdqm = 1;
			}else{
				isdqm = 0;
			}
		}
		
		if(s[i] == '/' && s[i+1] == '/' && isdqm == 0){
			isn = 1;
		}
		// 取消单行不打印
		if(isn == 1 && s[i] == '\n'){
			isn = 0;
		}
		
		
		if(s[i] == '/' && s[i+1] == '*'){
			issn = 1;
		}
		
		// 打印输出
		if(isn == 0 && issn == 0){
			putchar(s[i]);
		}
		
		// 取消多行不打印
		if(issn == 1 && s[i] == '/'&& s[i-1] == '*'){
			issn = 0;
		}
	}
}

int getlines(char s[], int len)
{
	int i;
	char c;
	for(i=0;i<len-1&&(c=getchar())!=EOF;i++)
		s[i]=c;
	s[i] = '\0';
	return i;
}