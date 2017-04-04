#include <stdio.h>

void expand(char s1[], char s2[]);

int main()
{
	char *s1[]= {"a-z","A-Z","0-9","a-b-c","a-z0-9","-a-z",NULL};
	
	char s2[1000];
	
	int i;
	
	i = 0;
	
	while(s1[i]){
		
		expand(s1[i], s2);
		printf("s1: %s\n", s1[i]);
		printf("s2: %s\n", s2);
		i++;
	}
	
	return 0;
}

void expand(char str[], char s2[])
{
	int i,j;
	char from,to;
	
	from = '\0';
	to = '\0';
	i = j = 0;
	while(str[i]){
		
		switch(str[i]){
			case '-':
				if(i==0 || str[i+1] == '\0'){
					s2[j++] = str[i];
				}else{
					from = str[i-1];
					to = str[i+1];
					if(from > to){
						s2[j++] = from;
						if(str[i+2] != '-'){
							s2[j++] = to;
						}
					}else if(from < to){
						while(from <= to){
							if(from == to && str[i+2] == '-'){
								break;
							}
							s2[j++] = from;
							from++;
						}
					}else{
						s2[j++] = from;
					}
					from = '\0';
					to = '\0';
				}
				break;
			default :
				if(str[i-1]=='-'||str[i+1]=='-'){
					break;
				}
				s2[j++] = str[i];
				break;
		}
		i++;
	}
	s2[j] = '\0';
}