#include <stdio.h>

int func1(int *);
int func2(int *);
int func3(int *);
int func4(int *);
int func5(int *);

int main()
{
    int (*(*acf)[5])(int *p);
    int (*array[5])(int *p);
    int i, num = 10;

    acf = &array;

    array[0] = func1;
    array[1] = func2;
    array[2] = func3;
    array[3] = func4;
    array[4] = func5;

    for(i=0;i<5;i++){
        printf("%d\n",(*(*acf)[i])(&num));
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
