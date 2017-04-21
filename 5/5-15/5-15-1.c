#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES    5000
#define MAXLENS     1024

char *lineptr[MAXLINES];

int getlines(char s[], int len);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsorts(void *lineptr[], int left, int right, int (*comp)(const void *, const void *));
int numcmp(char *, char *);
int fstrcmp(char *, char *);
void reverse(char *lineptr[], int, int);

int main(int argc, char **argv)
{
    int nlines, i = 1,k;
    char *p;
    int numeric = 0,reveric = 0,fcase = 0;

    while(i++ < argc){
        p = *++argv;
        k = 0;
        if(p[k++] == '-')
            while( p[k] != '\0'){
                if(p[k] == 'n')
                    numeric = 1;
                else if(p[k] == 'r')
                    reveric = 1;
                else if(p[k] == 'f')
                    fcase = 1;

                k++;
            }
    }

    if( (nlines = readlines(lineptr, MAXLINES) ) > 0 ){
            qsorts( (void**) lineptr, 0, nlines - 1,
                    (
                        numeric? (int (*)(const void *, const void *))numcmp: ( fcase?  (int (*)(const void *, const void *))fstrcmp:   (int (*)(const void *, const void *))strcmp )
                    )
                   );
            reverse(lineptr, nlines, reveric);
            writelines(lineptr, nlines);
    }else{
        printf("input too big to sort.\n");
        return 1;
    }
    return 0;
}

int fstrcmp(char *s1, char *s2)
{
    char v1[MAXLENS], v2[MAXLENS];
    int i;
    for(i=0;s1[i]!='\0';i++){
        if(s1[i] >= 65 && s1[i] <= 90){
            v1[i] = s1[i] - 'A' + 'a';
        }else
            v1[i] = s1[i];
    }
    v1[i] = '\0';
    for(i=0;s2[i]!='\0';i++){
        if(s2[i] >= 65 && s2[i] <= 90){
            v2[i] = s2[i] - 'A' + 'a';
        }else
            v2[i] = s2[i];
    }
    v2[i] = '\0';
    return strcmp(v1, v2);
}

void reverse(char *lineptr[], int nlines, int n)
{
    int i ,j;
    char *tmp;
    if(n > 0){
        for(i = 0, j = nlines-1; i<j;i++,j--){
            tmp = lineptr[i];
            lineptr[i] = lineptr[j];
            lineptr[j] = tmp;
        }
    }
}

void qsorts(void *v[], int left, int right, int (*comp)(const void *,const void *))
{
    int i, last;
    void swap(void *v[], int, int);
    if(left >= right)
        return ;
    swap(v, left, (left+right)/2);
    last = left;
    for(i = left + 1; i<=right; i++)
        if((*comp)(v[i], v[left])<0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsorts(v, left, last -1, comp);
    qsorts(v, last+1, right, comp);
}

void swap(void *v[], int i, int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int numcmp(char *s1, char *s2)
{
    double f1,f2;
    f1 = atof(s1);
    f2 = atof(s2);
    if(f1 == f2)
        return 0;
    else if(f1 > f2)
        return 1;
    else
        return -1;
}

void writelines(char *lineptr[], int nlines)
{
    int tmp = nlines;
    while(nlines-- > 0)
        printf("ln:%d %s", tmp - nlines, *lineptr++);
}

int getlines(char *s, int len)
{
    int i = 0;
    char c;
    while(i<len-1 && (c=getchar())!=EOF && c!='\n')
        s[i++] = c;
    if (c=='\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int readlines(char *lineptr[], int nlines)
{
    int len, nline = 0;
    char line[MAXLENS],*p;

    while( (len = getlines(line, MAXLENS)) > 0){
        if(line[len-1] != '\n')
            p = malloc(sizeof(char) * (len + 1));
        else
            p = malloc(sizeof(char) * len);

        if(nline > nlines-1 || p == NULL)
            return -1;

        strcpy(p, line);
        if(line[len-1] != '\n'){
            *(p+len) = '\n';
            *(p+len+1) = '\0';
        }
        lineptr[nline++] = p;
    }
    return nline;
}
