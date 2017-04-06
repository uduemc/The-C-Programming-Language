#include <stdio.h>

void squeeze(char s1[], char s2[]);
int main()
{
	char s1[] = "babcdefghijklmn\0";
	char s2[] = "bdf\0";
	squeeze(s1, s2);
	printf("%s\n",s1);
	return 0;
}

void squeeze(char s1[], char s2[])
{
	int i,j,k;
	for(i=0,j=0;s1[i]!='\0';i++){
		for(k=0;s2[k]!='\0';k++){
			if(s1[i] == s2[k]){
				i++;
			}
		}
		s1[j] = s1[i];
		j++;
	}
	s1[j] = '\0';
}