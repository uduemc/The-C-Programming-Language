#include <stdio.h>

int func(int *);

int main()
{
    int (*acf)(int *p);
    int num = 10;

    acf = func;

    printf("%d",(*acf)(&num));

    return 0;
}

int func(int *p)
{
    return *p + 1;
}
