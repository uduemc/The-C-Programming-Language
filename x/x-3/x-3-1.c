#include <stdio.h>
#include <stdlib.h>

typedef struct List{
    int num;
    struct List* next;
}List, *PList;

PList create(int no)
{
    PList p = malloc(sizeof(List));
    if(p == NULL){
        printf("Out of space");
        exit(1);
    }
    p->next = NULL;
    p->num = no;
    return p;
}

void insert(int no, PList pl)
{
    PList last;
    last = pl;
    while(last->next != NULL)
        last = last->next;
    last->next = create(no);
}

void printPList(PList pl)
{
    PList tmp;
    tmp = pl;
    do{
        printf("%d ",tmp->num);
        tmp = tmp->next;
    }while(tmp!=pl);
}

// 开始数数
PList Josephus(int k,PList header)
{
    PList tmp, prev;
    int i, time, count;

    tmp = header->next;
    count = 2;
    while(tmp->next != header){
        tmp = tmp->next;
        count++;
    }

    time = 0;
    tmp = header;

    while( (count - time++) > 2){
        for(i=1;i<k;i++){
            prev = tmp;
            tmp = tmp->next;
        }
        prev->next = tmp->next;
        free(tmp);
        tmp = prev->next;
    }

    return tmp;
}

int main()
{
    int i;
    PList header, tmp;
    header = create(1);
    for(i=2;i<=41;i++)
        insert(i,header);
    tmp = header;
    while(tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = header; // 循环链表达成

    // 打印
    printPList(header);

    header = Josephus(3, header);

    printf("\nlast two num: ");
    // 打印
    printPList(header);

    return 0;
}