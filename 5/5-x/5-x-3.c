#include <stdio.h>

int func1(int *);
int func2(int *);
int func3(int *);
int func4(int *);
int func5(int *);

int main()
{
    int (*acf[5])(int *p);
    int k = 0,num = 10;

    acf[0] = func1;
    acf[1] = func2;
    acf[2] = func3;
    acf[3] = func4;
    acf[4] = func5;

    while(k < 5){
        printf("%d\n",(*acf[k])(&num));
        k++;
    }

    return 0;
}

int func1(int *p)
{
    return *p + 1;
}
int func2(int *p)
{
    return *p + 2;
}
int func3(int *p)
{
    return *p + 3;
}
int func4(int *p)
{
    return *p + 4;
}
int func5(int *p)
{
    return *p + 5;
}
