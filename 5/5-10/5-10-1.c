#include <stdio.h>
#include <ctype.h>
/**
 * expr 2 3 4 + *
 */

int buffer[100];
int bkey = 0;
int pop();
void push(int num);

int main(int argc, char *argv[])
{
    int sign;
    int num;
    int temp;
    int n;
    while(--argc > 0 && ++argv){
        // *argv ×ª»¯³É int
        if(**argv == '-'){
            sign = -1;
        }else{
            sign = 1;
        }
        num = n = 0;
        while(**argv != '\0' && **argv >= '0' && **argv <= '9'){
            num = num*10 + (**argv - '0');
            n++;
            (*argv)++;
        }
        num = num*sign;
        if(n > 0){
            printf("push num: %d\n",num);
            push(num);
        }else{
            switch(**argv){
            case '+':
                push(pop() + pop());
                break;
            case '-':
                temp = pop();
                push(pop() - temp);
                break;
			case '*':
                push(pop()*pop());
                break;
            default:
                printf("Undefine commond: %s\n",*argv);
                break;
            }
        }
    }
    printf("result: %d\n",pop());
    getchar();
    return 0;
}


int pop()
{
    if(bkey <= 0 ){
        printf("error: bkey <= 0;");
        return 0;
    }else{
        return buffer[bkey--];
    }
}
void push(int num)
{
    if(bkey > 100){
        printf("error: bkey > 100;");
    }else{
        buffer[++bkey] = num;
    }
}
