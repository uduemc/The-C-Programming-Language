#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLENGTH 20

void ptf(char c, int flag);

int main(int argc, char **argv)
{
    char c;
    int n=0,flag;

    if(argc > 1){
        while(*++argv){
            flag = atoi(*argv);
        }
    }
    if(flag != 8 || flag != 16)
        flag = 10;

    while((c=getchar()) != EOF){
        if(c == '\n'){
            n = 0;
            putchar(c);
            continue;
        }

        if(n > MAXLENGTH-1){
            continue;
        }else{
            if(isalpha(c)){
                ptf(c, flag);
            }else
                putchar(c);
            n++;
        }
    }

    return 0;
}

void ptf(char c, int flag)
{
    if(flag == 8)
        printf("%o",c);
    else if(flag == 16)
        printf("%X",c);
    else if(flag == 10)
        printf("%d",c);
    else
        printf("Undefine flag num");
}
