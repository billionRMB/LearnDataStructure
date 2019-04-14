/*************************************************************************
	> File Name: queue.cpp
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年04月14日 星期日 13时01分48秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int*data;
    int count,size,head,tail;
}queue;

queue* init(int n){
    queue * q = (queue*)malloc(sizeof(queue));
    q->data = (int*)malloc(sizeof(int)*n);
    q->count = 0;
    q->size = n;
    q->tail = 0;
    q->head = 0;
    return q;
}

void clear(queue *q){
    free(q->data);
    free(q);
    return;
}

int push(queue *q ,int val){
    if(q -> count == q->size)return 0;
    q->data[q->tail] = val;
    q->tail = (q->tail+1)%q->size;
    q->count ++;
    return 1;
}

int empty(queue *q){
    return q -> count == 0;
}

int pop(queue *q){
    if(empty(q))return 0;
    q -> head = (q -> head + 1) % q -> size;
    q -> count -- ;
    return 1;
}

int front(queue *q){
    return q->data[q->head];
}

void output(queue *q) {
    printf("[");
    for (int i = 0; i < q->count; i++) {
        int ind = (q->head + i) % q->size;
        printf(" %d", q->data[ind]);
    }
    printf("]\n");
    return ;
}

int main(){
    #define MAX_OP 20
    queue *q = init(5);
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 4, val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("insert %d to queue\n", val);
                push(q, val);
            } break;
            case 3: {
                printf("pop %d from queue\n", front(q));
                pop(q);
            } break;
        }
        output(q);
    }
    clear(q);
    return 0;
}
