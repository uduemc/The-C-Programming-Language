#include <stdio.h>
int main(){
	// ��Linux������EOF�ķ�ʽ��Ctrl+D
	// ��Windows������EOF�ķ�ʽ��Ctrl+z
	printf("%d\n",getchar()!=EOF);
    return 0;
}


