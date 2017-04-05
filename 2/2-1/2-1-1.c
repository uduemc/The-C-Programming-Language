#include <stdio.h>
#include <limits.h>

int main()
{
	printf("char bit is %d\n",CHAR_BIT);
	printf("signed char min is %d\n",SCHAR_MIN);
	printf("signed char max is %d\n",SCHAR_MAX);
	printf("unsigned char max is %d\n",UCHAR_MAX);
	printf("short int min is %d\n",SHRT_MIN);
	printf("short int max is %d\n",SHRT_MAX);
	printf("unsigned short max is %d\n",USHRT_MAX);
	printf("int min is %d\n",INT_MIN);
	printf("int max is %d\n",INT_MAX);
	printf("unsigned int max is %d\n",UINT_MAX);
	printf("long int min is %d\n",LONG_MIN);
	printf("long int max is %d\n",LONG_MAX);
	printf("unsigned long max is %d\n",ULONG_MAX);
	return 0;
}