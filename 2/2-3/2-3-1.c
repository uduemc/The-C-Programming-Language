#include <stdio.h>

int htoi(char s[]);

int main()
{
	char s[9];
	
	int result;
	
	printf("Enter the 8 bit decimal number containing 0x:\n");
	
	scanf("%s",s);
	
	s[8] = '\0';
	
	result = htoi(s);
	
	printf("%s\n",s);
	
	printf("result: %d\n",result);
	
	return 0;
}

int htoi(char s[])
{
	int i,val;
	int result;
	if(s[0] != '0')
		return -1;
	
	if(!(s[1] == 'x' || s[1] == 'X')){
		return -1;
	}
	result = '0' + s[1];
	for(i = 2; s[i]!='\0'; i++){
		val = s[i];
		if((val >= '0' && val <= '9') ||(val >= 'A' && val <= 'F') || (val >= 'a' && val <= 'f'))
			result = result + val;
		else
			return -1;
	}
	
	return result;
}