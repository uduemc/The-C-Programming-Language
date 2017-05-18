#include <stdio.h>
#include <stdlib.h>

#define frand() ((double)rand() / (RAND_MAX+1.0))

int main(int argc, char **argv)
{

    printf("%f\n",frand());
    printf("%f\n",frand());
    printf("%f\n",frand());
    printf("%f\n",frand());

    return 0;
}
