#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    FILE *fp1, *fp2;
    char *fname1 = "C:\\fname1.txt";
    char *fname2 = "C:\\fname2.txt";
    char fline1[1024], fline2[1024];
    int i;

    fp1 = fopen(fname1,"r");
    fp2 = fopen(fname2,"r");

    if(fp1 == NULL){
        printf("file: %s open error.\n",fname1);
        exit(1);
    }

    if(fp2 == NULL){
        printf("file: %s open error.\n",fname2);
        exit(1);
    }

    i = 1;
    while(fgets(fline1, 1024, fp1) && fgets(fline2, 1024, fp2)){
        if(strcmp(fline1,fline2) != 0){
            printf("%s %d : %s",fname1,i,fline1);
            printf("%s %d : %s",fname2,i,fline2);
        }
        i++;
    }
    return 0;
}

