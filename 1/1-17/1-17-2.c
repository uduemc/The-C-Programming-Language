#include <stdio.h>
int main(){
	// ��дһ�����򣬴�ӡ���ȴ���80���ַ�������������
	// �Լ���д��
	// Ȼ�����ַ�ʽ��������!
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
		// ��Ҫ�洢ǰ80���ַ�
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