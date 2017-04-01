#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1024
#define COLUMN 25
int getlines(char s[], int len);
void columnForLine(char s[], int len);
int main()
{
    char buffer[MAX_LENGTH];
    while(getlines(buffer,MAX_LENGTH)>0){
        columnForLine(buffer,MAX_LENGTH);
    }
    return 0;
}

void columnForLine(char buffer[], int len){
    int cln;    // 当前的列
    char words[len];
    int i,j,k;
    k = cln = 0;
    for(i=0;buffer[i]!='\0';i++){
        cln++;
        if(buffer[i] == '\n'){
            continue;
        }
        if(buffer[i] == ' ' || buffer[i] == '\t'){
            words[k] = '\0';
            for(j=0;words[j]!='\0';j++){
                putchar(words[j]);
            }
            putchar(buffer[i]);
            k = 0;
        }else{
            words[k] = buffer[i];
            if(k > 0 && cln == 0){
                cln = k;
                printf("%d",cln);
            }
            k++;
        }
        if(cln > 25){
            putchar('\n');
            cln = 0;
        }
    }
    words[k] = '\0';
    for(j=0;words[j]!='\0';j++){
        putchar(words[j]);
    }
}

int getlines(char s[], int len)
{
    int i;
    char c;
    for(i=0;i<len-1&&(c=getchar())!=EOF&&c!='\n';i++)
        s[i]=c;
    if(c=='\n')
        s[i++]=c;
    s[i]='\0';
    return i;
}
