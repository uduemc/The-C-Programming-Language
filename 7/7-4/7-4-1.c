#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void minscanf(char *fmt, ...);

int main(int argc, char **argv)
{
    int i;
    char str[1024];
    minscanf("in i: %d", &i);
    printf("out i: %d\n",i);


    minscanf("in str: %s", str);
    printf("out str: %s\n",str);

    return 0;
}

void minscanf(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;
    int *ival;


    va_start(ap, fmt);
    for(p = fmt; *p != '\0'; p++){
        if(*p != '%'){
            putchar(*p);
            continue;
        }
        switch(*++p){
        case 'd':
            ival = va_arg(ap, int *);
            scanf("%d",ival);
            break;
        case 's':
            sval = va_arg(ap, char *);
            scanf("%s",sval);
            break;
        default:
            putchar(*p);
            break;
        }
    }
    va_end(ap);
}
