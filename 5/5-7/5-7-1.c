#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXLINES 	1000
#define MAXLEN		1024

char *lineptr[MAXLINES];


int readlines(char *lineptr[], char buffer[][MAXLEN], int nlines);
void writelines(char *lineptr[], int nlines);
void qsorts(char *lineptr[], int left, int right);
int getlines(char *, int);

int main()
{
    char buffer[MAXLINES][MAXLEN];
	int nlines;
	if((nlines = readlines(lineptr, buffer, MAXLINES)) >= 0){
		qsorts(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	}else{
		printf("error: input too big to sort\n");
		return 1;
	}
}

int readlines(char *lineptr[], char (*buffer)[MAXLEN], int maxlines)
{
	int len, nlines;
    nlines = 0;
    while((len = getlines(*buffer,MAXLEN)) > 0){
        if(nlines >= maxlines){
            return -1;
        }else{
            (*buffer)[len-1] = '\0';
            lineptr[nlines++] = *buffer;
        }
        buffer++;
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    while(nlines-- > 0)
        printf("%s\n",*lineptr++);
}

void qsorts(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);
    if(left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for(i = left + 1; i<= right; i++)
        if(strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsorts(v, left, last-1);
    qsorts(v, last+1, right);
}
void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
int getlines(char *line, int n)
{
    char c;
    int i;
    for(i = 0;i<n-1&&(c=getchar())!=EOF&&c!='\n';i++)
        line[i] = c;
    if(c=='\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}
