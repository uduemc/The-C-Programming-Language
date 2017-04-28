#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    char c;
    if(argc > 1){
        while(*++argv){
            printf("argv: %s\n",*argv);

            while( (c=*(*argv)++) != '\0'){
                if(isalpha(c)){
                    if(c >= 'A' && c <= 'Z'){
                        c = tolower(c);
                    }else if(c >= 'a' && c <= 'z'){
                        c = toupper(c);
                    }
                }
                printf("%c",c);
            }
			printf("\n");
        }
    }
    return 0;
}
