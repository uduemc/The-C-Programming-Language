#include <stdio.h>
/**
编写一个程序，查找C语言程序中的基本语法错误
*/
#define 	TRUE		1
#define		FALSE		0
#define 	MAXLENGHT	2048

// global

int getlines(char s[], int len);
int checkCode(char s[], int len);

int main()
{
	char buffer[MAXLENGHT];
	
	while(getlines(buffer, MAXLENGHT) > 0){
		// 检测是否存在错误
		if(FALSE == checkCode(buffer, MAXLENGHT))
			printf("check error");
		printf("check over!");
	}
	return 0;
}

int checkCode(char s[], int len)
{
	int result;
	int i,j;
	int check[6][2]={0};	//	0-() 1-[] 2-{} 3-'' 4-"" 5-/**/
	int issqm;			// 是否单引号中
	int isdqm;			// 是否双引号中
	
	result = TRUE;
	issqm = isdqm = 0;
	for(i=0;s[i]!='\0';i++){
		
		// 是否单引号中
		if(s[i] == '\'' && s[i-1] != '\\' && s[i-2] != '\\'){
			if(issqm == 0)
				issqm = 1;
			else
				issqm = 0;
		}
		
		// 是否双引号中
		if(issqm == 0 && s[i] == '"'){
			if(isdqm == 0)
				isdqm = 1;
			else
				isdqm = 0;
		}
		
		if(issqm == 1 || isdqm == 1){
			continue;
		}
		
		if(s[i]=='(')
			check[0][0]++;
		if(s[i]==')')
			check[0][1]++;
		
		if(s[i]=='[')
			check[1][0]++;
		if(s[i]==']')
			check[1][1]++;
		
		if(s[i]=='{')
			check[2][0]++;
		if(s[i]=='}')
			check[2][1]++;
		
		if(s[i]=='\'')
			check[3][0]++;
		if(s[i]=='\'')
			check[3][1]++;
		
		if(s[i]=='"')
			check[4][0]++;
		if(s[i]=='"')
			check[4][1]++;
		
		if(s[i]=='/' && s[i+1]=='*')
			check[5][0]++;
		if(s[i]=='*' && s[i+1]=='/')
			check[5][1]++;
	}
	for (j=0;j<6;j++){
		if(check[j][0] != check[j][1] && result == TRUE){
			printf("j:%d 0-%d, 1-%d \n",j,check[j][0],check[j][1]);
			result = FALSE;
		}
	}
	return result;
}

int getlines(char s[], int len)
{
	char c;
	int i;
	for(i=0;i<MAXLENGHT-1&&(c=getchar())!=EOF;i++)
		s[i] = c;
	s[i] = '\0';
	return i;
}