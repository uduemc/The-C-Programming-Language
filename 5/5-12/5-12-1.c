#include <stdio.h>
#include <stdlib.h>

int getlines(char *, int);
void entab(char *, int);
void detab(char *, int);
int main(int argc, char **argv)
{
    int tab,a=0,b=0;
    char *p;
    char buffer[1024];

    if(argc == 3){
        p = *++argv;
        if(*p == '-'){
            p++;
            a = atoi(p);
        }

        p = *++argv;
        if(*p == '+'){
            p++;
            b = atoi(p);
        }
    }

    if(a && b && b > a)
        tab = b - a;
    else
        tab = 8;

    printf("tab: %d\n",tab);

    while(getlines(buffer, 1024) > 0){
        printf("entab: ");
        entab(buffer, tab);
        printf("detab: ");
        detab(buffer, tab);
    }
    return 0;
}

void detab(char *buffer, int tab)
{
    int i,s;
    for(i = 0;buffer[i]!='\0';i++){
        if(buffer[i] == '\t'){
            for(s = 0;s<tab;s++){
                putchar(' ');
            }
        }else{
            putchar(buffer[i]);
        }
    }
}

void entab(char *buffer, int tab)
{
    int i,s;
    s = 0;
    for(i = 0;buffer[i]!='\0';i++){
        if(buffer[i] == ' '){
            s++;
        }else{
            if(s > 0){
                for(;s>0;s--){
                    putchar(' ');
                }
            }
        }

        if(s == tab){
            putchar('\t');
            s = 0;
        }else{
            if(buffer[i] != ' ')
                putchar(buffer[i]);
        }
    }
}

int getlines(char *buffer, int len)
{
    char c;
    int i;
    for(i = 0;i < len-1 && (c=getchar())!=EOF && c!='\n';i++)
        buffer[i] = c;
    if(c=='\n')
        buffer[i++] = c;
    buffer[i] = '\0';
    return i;
}
