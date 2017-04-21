#include <stdio.h>

int func1(int *);
int func2(int *, int (*)(int *));

int main()
{
    int (*acf)(int *p, int (*f)(int*));
    int (*ft)(int*);
    int num = 10;

    ft = func1;
    acf = func2;

    printf("%d",(*acf)(&num, ft));

    return 0;
}

int func1(int *p)
{
    return *p + 1;
}

int func2(int *p, int (*f)(int *))
{
    return *p + (*f)(p);
}
