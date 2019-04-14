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
    int head,tail,length;// 长度
    int count;//用来循环队列
}queue;

queue *init(int n){
    queue *q = (queue*)malloc(sizeof(queue));
    q -> length = n;
    q -> data = (int *)malloc(sizeof(int) * n);
    q -> head = 0;
    q -> count = 0;
    q -> tail = -1;// 队列的最后一个元素还是最后一个没有元素的位置
    return q;
}

int empty(queue *q){
    return q -> count == 0;
}

int push(queue *q,int value){
    if(q -> count == q -> length)return 0 ;
    q -> data[(q->tail)++ ] = value;
    if(q -> tail >= q -> length)q -> tail -= q-> length;
    q -> count ++;
    return 1;
}

void pop(queue *q){
    if(empty(q))return;
    q -> head += 1;
    if(q -> tail >= q -> length)q -> tail -= q-> length;
    q -> count --;
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
    for(int i = 0;i < q->count;i ++){
        int ind = (q ->head + i) % q->length;
        printf(" %d",q -> data[ind]);
    }
    printf("]\n");
}


int main(){
    #define MAX_OP 20
    srand(time(0));
    queue *q = init(20);
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
