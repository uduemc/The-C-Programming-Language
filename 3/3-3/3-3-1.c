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
	int j=0,i = 0;
	char from= '\0';
	char to= '\0';
	while(str[i]){
		if((str[i] == '-' && from == '\0') || (str[i] == '_' && from == '\0')){
			s2[j++] = str[i];
			continue;
		}
		if(from == '\0'){
			s2[j++] = from = str[i];
		}else{
			if(str[i] == '-'){
				if(str[i+1] == '-'){
					s2[0] = '\0';
				}else{
					if(str[i+1] > from){
						to = str[i+1];
						i++;
						// Ñ­»·
						while(from <= to){
							s2[j++] = from;
							from ++;
						}
						to = '\0';
						from = '\0';
					}else{
						s2[j++] = from;
						from = str[i];
					}
				}
				
				// && str[i+1] != '-' && str[i+1] > from
				
			}else{
				s2[j++] = from;
				from = str[i];
			}
		}
		
		i++;
	}
	s2[j] = '\0';
}