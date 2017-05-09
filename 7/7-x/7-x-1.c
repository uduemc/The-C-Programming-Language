#include <stdio.h>

int main(int argc, char **argv)
{
    FILE* fp;
    void filecopy(FILE *, FILE *);

    if(argc == 1)
        filecopy(stdin, stdout);
    else
        while(--argc > 0){
            if((fp = fopen(*++argv,"r")) == NULL){
                printf("cat: can't open %s\n",*argv);
                return 1;
            }else{
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    printf("\n");
    return 0;
}

void filecopy(FILE *f, FILE *t)
{
    int c;
    while((c=getc(f)) != EOF)
        putc(c, t);
}
void filecopy(FILE *, FILE *);
