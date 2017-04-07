#include <stdio.h>

#define MAXLENGTH 20000

int getlines(char s[], int len);
void escape(char t[], char s[], int len);
void deescape(char t[], char s[], int len);
int main()
{
	char s[MAXLENGTH];
	char t[MAXLENGTH];
	int i;
	while(getlines(s, MAXLENGTH) > 0){
		escape(t, s, MAXLENGTH);
		printf("%s\n",t);
		while(i < MAXLENGTH - 1){
			if(s[i] == '\0')
				break;
			s[i] = '\0';
			i++;
		}
		deescape(t, s, MAXLENGTH);
		printf("%s\n",s);
	}
	
	return 0;
}

void deescape(char t[], char s[], int len)
{
	int j=0,i=0;
	while(i<len-1 && j<len-1){
		if(t[i] == '\0')
			break;
		if(t[i] == '\\'){
			switch(t[i+1]){
				case 'n':
					s[j] = '\n';
					i++;
					break;
				case 't':
					s[j] = '\t';
					i++;
					break;
				case 's':
					s[j] = ' ';
					i++;
					break;
				default :
					s[j] = t[i];
					break;
			}
		}else{
			s[j] = t[i];
		}
		j++;
		i++;
	}
	s[j] = '\0';
}

void escape(char t[], char s[], int len)
{
	int j=0,i=0;
	while(i<len-1 && j<len-1){
		if(s[i] == '\0')
			break;
		
		switch(s[i]){
			case '\n':
				t[j++] = '\\';
				t[j] = 'n';
				break;
			case '\t':
				t[j++] = '\\';
				t[j] = 't';
				break;
			case ' ':
				t[j++] = '\\';
				t[j] = 's';
				break;
			default:
				t[j] = s[i];
				break;
		}
		
		j++;
		i++;
	}
	t[j] = '\0';
}

int getlines(char s[], int len)
{
	int i;
	char c;
	for(i=0; i<len-1 && (c=getchar())!=EOF;i++)
		s[i] = c;
	s[i] = '\0';
	return i;
}