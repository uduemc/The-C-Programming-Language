#include <stdio.h>
int main(){
	// ��дһ�������븴�Ƶ�����ĳ���
	// �������е��Ʊ���滻�� \t ���ѻ��˷��滻�� \b���ѷ�б���滻Ϊ\\
	// �������Խ��Ʊ���ͻ��˷��Կɼ��ķ�ʽ��ʾ����
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