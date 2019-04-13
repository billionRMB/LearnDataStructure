/*************************************************************************
	> File Name: 4.test.stack.cpp
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年04月12日 星期五 17时10分32秒
 ************************************************************************/
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

typedef struct stack{
    int *data;
    int top,size;
}stack;

stack *init(int n){
    stack * s = (stack*)malloc(sizeof(stack));
    s -> data = (int *)malloc(sizeof(int));
    s -> top = -1;
    s -> size = n;
    return s;
}

int empty(stack *s){
    return s->top == -1;
}

int top(stack *s){
    if(empty (s))return 0;
    return s->data[s->top];
}

int push(stack *s,int val){
    if(s -> top + 1 == s -> size )return 0;
    s->top ++;
    s->data[s->top] = val;
    return 1;
}

void pop(stack*s){
    if(empty(s))return ;
    s -> top -= 1;
    return ;
}

void clear(stack *s){
    if(s == NULL)return ;
    free(s -> data);
    free(s );
    return ;
}

void output(stack *s){
    printf("stack = [");
    for(int i = s -> top;i >= 0 ;i --){
        printf(" %d",s->data[i]);
        i && printf(",");
    }
    printf("]\n");
}


int main(){
    srand(time(0));
    #define MAX_OP 20
    stack *s = init(MAX_OP);
    for(int i = 0;i < MAX_OP;i ++){
        int op = rand()%4,val = rand()%100;
        switch(op){
            case 0:
            case 1:
            case 2:
                push(s,val);
                printf("push %d to stack\n",val);
                output(s);
                break;
            case 3:
                printf("pop %d from stack\n",top(s));
                pop(s);
                output(s);
                break;
        }
    }
    return 0;
}
