#include <stdio.h>

int any(char s1[], char s2[]);

int main()
{
	char s1[] = "http://www.baidu.com/\0";
	char s2[] = "www\0";
	printf("s1: %s\ns2: %s\nany: %d\n",s1,s2,any(s1, s2));
	return 0;
}

int any(char s1[], char s2[])
{
	int i,k,tmp;
	for(i = 0;s1[i]!='\0';i++){
		tmp = i;
		for(k = 0;s2[k]!='\0';k++){
			if(s1[tmp] == s2[k]){
				tmp++;
			}else{
				tmp = i;
				break;
			}
		}
		if(tmp!=i){
			return i;
		}
	}
	return -1;
}