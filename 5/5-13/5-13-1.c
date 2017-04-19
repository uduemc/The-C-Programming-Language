#include <stdio.h>
#include <stdlib.h>

#define MAXLINES    1000
#define MAXLENGTH   1024

int getlines(char *, int);

int main(int argc, char **argv)
{
    int i,f,n = 0;
    char *p;
    char buffer[MAXLINES][MAXLENGTH];

    if(argc >= 2){
        p = *++argv;
        if(*p == '-'){
            p++;
            n = atoi(p);
        }
    }

    i = 0;
    while(getlines(buffer[i], MAXLENGTH) > 0 && i++<MAXLINES)
        ;
    if(n >= i){
        f = 0;
    }else{
        f = i - n;
    }
    for(;f<i;f++)
        printf("line %d: %s",f+1, buffer[f]);

    return 0;
}

int getlines(char *s, int len)
{
    int i;
    char c;
    for(i=0;i<len-1&&(c=getchar())!=EOF&&c!='\n';++i)
        s[i] = c;
    if(c=='\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
