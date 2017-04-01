#include <stdio.h>

#define MAX_LENGTH 10240

int getlines(char s[], int len);	// ��ȡ������ַ�
int printCode(char s[], int len);	// ��ӡȥ��ע�͵Ĵ���
int main()
{
	// ���Զ���һ���ַ���
	// Double quotation marks
	char *str = "\\��������Ʒ���, // ��ά�������㳦";
	char buffer[MAX_LENGTH];
	while(getlines(buffer,MAX_LENGTH) > 0){
		printCode(buffer,MAX_LENGTH);
	}
	return 0;
}

/**
 * ������Ҫ������ַ�
 * isn ����ע��
 * isnn ����ע��
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
		// ȡ�����в���ӡ
		if(isn == 1 && s[i] == '\n'){
			isn = 0;
		}
		
		
		if(s[i] == '/' && s[i+1] == '*'){
			issn = 1;
		}
		
		// ��ӡ���
		if(isn == 0 && issn == 0){
			putchar(s[i]);
		}
		
		// ȡ�����в���ӡ
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