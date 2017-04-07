#include <stdio.h>
#include <time.h>


#define NUMBER 500000

int binsearch1(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int main()
{
	int num[NUMBER];
	int i,time;
	int x;
	
	// num[n] 1~20000
	for(i=0;i<NUMBER;i++)
		num[i] = i+1;
	
	time = clock();
	x = 40;
	while(x < NUMBER-1){
		binsearch1(x, num, NUMBER);
		x++;
	}
	time = clock() - time;
	printf("binsearch1(%d, num[], %d) == %d time: %d\n", x, NUMBER, binsearch1(x, num, NUMBER), time);
	
	
	time = clock();
	x = 40;
	while(x < NUMBER-1){
		binsearch2(x, num, NUMBER);
		x++;
	}
	time = clock() - time;
	printf("binsearch2(%d, num[], %d) == %d time: %d\n", x, NUMBER, binsearch2(x, num, NUMBER), time);
	return 0;
}


int binsearch1(int x, int num[], int n)
{
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	while(low <= high){
		mid = (low + high) / 2;
		if(x < num[mid])
			high = mid;
		else if(x > num[mid])
			low = mid;
		else
			return mid;
	}
	return -1;
}

int binsearch2(int x, int num[], int n)
{
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	mid = (low + high) / 2;
	while(low <= high && x != num[mid]){
		if(x < num[mid])
			high = mid ;
		else
			low = mid ;
		mid = (low + high) / 2;
	}
	if(x == num[mid])
		return mid;
	return -1;
}
