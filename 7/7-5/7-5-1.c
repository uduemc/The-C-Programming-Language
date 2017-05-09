#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXSIZE 1000

int buffer[MAXSIZE];
int k = 0;

void push(int);
int pop(void);
int iend(char *);

int main(void)
{
    char str[MAXSIZE];

    while(1){
        scanf("%s",str);
        if(!iend(str))
            break;
        if(isdigit(*str)){
            push(atoi(str));
            continue;
        }
        switch(*str){
        case '+':
            push(pop() + pop());
            break;
        }
    }

    printf("%d",pop());
    return 0;
}

int iend(char *str1)
{
    char *str = "-1";
    if(strcmp(str1, str) == 0)
        return 0;
    return 1;
}

void push(int num)
{
    if(k > MAXSIZE-1)
        printf("error: k > MAXSIZE-1");
    else
        buffer[++k] = num;
}

int pop(void)
{
    if(k < 0){
        printf("error: k < 0");
        return 0;
    }else
        return buffer[k--];

}
