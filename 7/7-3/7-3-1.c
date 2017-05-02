#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void minprintf(char *fmt, ...);

int main(int argc, char **argv)
{
    minprintf("int: %d %x %X, %% char: %c\n", 15, 15, 15, 'b');
    return 0;
}

void minprintf(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt);
    for(p = fmt; *p != '\0'; p++){
        if(*p != '%'){
            putchar(*p);
            continue;
        }
        switch(*++p){
        case 'd':
            ival = va_arg(ap, int);
            printf("%d",ival);
            break;
        case 'f':
            dval = va_arg(ap, double);
            printf("%f",dval);
            break;
        case 's':
            for(sval = va_arg(ap, char*);*sval != '\0';sval++)
                putchar(*sval);
        case 'c':
            ival = va_arg(ap, int);
            putchar(ival);
            break;
        case 'x':
            ival = va_arg(ap, int);
            printf("%x",ival);
            break;
        case 'X':
            ival = va_arg(ap, int);
            printf("%X",ival);
            break;
        default:
            putchar(*p);
            break;
        }
    }
    va_end(ap);
}
