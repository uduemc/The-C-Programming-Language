#include <stdio.h>
int main(){
	// 在Linux下输入EOF的方式是Ctrl+D
	// 在Windows下输入EOF的方式是Ctrl+z
	printf("%d\n",getchar()!=EOF);
    return 0;
}


