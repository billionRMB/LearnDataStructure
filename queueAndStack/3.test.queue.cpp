/*************************************************************************
	> File Name: 3.test.queue.cpp
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年04月12日 星期五 16时57分24秒
 ************************************************************************/
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

typedef struct queue{
    int *data;
    int head,tail,length;
}queue;

queue *init(int n){
    queue *q = (queue*)malloc(sizeof(queue));
    q -> length = n;
    q -> data = (int *)malloc(sizeof(int) * n);
    q -> head = 0;
    q -> tail = -1;
    return q;
}

int push(queue *q,int value){
    if(q -> tail + 1 == q -> length)return 0;
    q -> tail ++;
    q -> data[q -> tail] = value;
    return 1;
}

int empty(queue *q){
    return q -> head > q -> tail;
}

void pop(queue *q){
    if(empty(q))return;
    q -> head += 1;
    return ;
}

int front(queue *q){
    if(empty(q))return 0;
    return q -> data[q -> head];
}

void clear(queue *q){
    if(q == NULL)return;
    free(q -> data);
    free(q);
    return ;
}

void output(queue *q){
    printf("queue = [");
    for(int i = q->head;i <= q->tail;i ++){
        printf(" %d",q -> data[i]);
        i == q->tail || printf(",");
    }
    printf("]\n");
}


int main(){
    #define MAX_OP 20
    srand(time(0));
    queue *q = init(MAX_OP);
    for(int i = 0;i < MAX_OP;i ++){
        int op = rand()%4, value = rand()%100;
        switch(op){
            case 0:
            case 1:
            case 2:
            push(q,value);
            printf("push %d to queue\n",value);
            output(q);
            break;
            case 3:
            printf("pop %d from queue\n",front(q));
            pop(q);
            output(q);
            break;
        }
    }
    return 0;
}
