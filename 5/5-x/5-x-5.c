#include <stdio.h>

int array[] = {1,2,3,4,5};

int (* func1(int *))[5];

int main()
{
    int (*(*acf)(int *))[5];
    int i,num = 10;
    int (*p)[5];

    acf = func1;
    p = (*acf)(&num);

    for(i=0; i<5; i++){
        printf("%d\n",(*p)[i]);
    }

    return 0;
}

int (* func1(int *p))[5]
{
    int i = 0;

    while(array[i]){
        array[i] = array[i] + *p;
        i++;
    }
    return &array;
}
