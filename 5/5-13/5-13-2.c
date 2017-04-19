#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES    1000
#define MAXLENGTH   1024

int getlines(char **, int, int);

int main(int argc, char **argv)
{
    int i,f,n = 0;
    char *p;
    char *buffer[MAXLINES];

    if(argc >= 2){
        p = *++argv;
        if(*p == '-'){
            p++;
            n = atoi(p);
        }
    }
    i = 0;
    while(getlines(buffer,i, MAXLENGTH) > 0 && i < MAXLINES - 1)
    {
        ++i;
    }
    if(n >= i){
        f = 0;
    }else{
        f = i - n;
    }
    for(;f<i;f++)
        printf("line %d: %s",f+1, buffer[f]);


    return 0;
}

int getlines(char *s[],int k, int len)
{
    int i;
    char c,buffer[len];
    for(i=0;i<len-1&&(c=getchar())!=EOF&&c!='\n';++i){
        buffer[i] = c;
    }
    if(c=='\n')
        buffer[i++] = c;
    buffer[i] = '\0';
    s[k] = malloc(sizeof(char) * i);
    strcpy(s[k],buffer);
    return i;
}
