#include <stdio.h>
// char ( *(*x())[5])();
typedef     char        (*FUNC_PTR)();
typedef     FUNC_PTR    (*x)[5];

char func1()
{
    return '1';
}

FUNC_PTR arr[5];
FUNC_PTR *p;

int main()
{
    FUNC_PTR *p;

    arr[0] = func1;

    p = &arr[0];


    printf("%c",(**p)());

    return 0;
}


