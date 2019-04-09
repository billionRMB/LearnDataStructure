/*************************************************************************
	> File Name: 1.vector.cpp
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年04月09日 星期二 19时03分27秒
 ************************************************************************/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef struct Vector{
    int *data;// void* 来代表任意类型
    int size,length;
}Vector;

Vector *init(int n){
    Vector *p = (Vector*) malloc(sizeof(Vector));
    p -> data = (int *)malloc(sizeof(int)*n);
    p -> size = n;
    p -> length = 0;
    return p;
}

void clear(Vector *v){
    if(v == NULL)return;
    free(v -> data);
    free(v);
    return ;
}

// calloc 申请并赋值为０
// malloc 仅申请
// realloc 重新分配
// 字节大小
int expand(Vector *v){
    // 注意内存泄露
    int extra_size = v->size;
    int*p;
    // 申请内存多次逐步减少
    while(extra_size){
        p = (int* )realloc(v->data,sizeof(int) * (v->size + extra_size));
        if(p)break;
        extra_size /= 2;
    }
    if(extra_size == 0)return 0;
    v->data = p;
    v->size *= 2;
    return 1;
}

// 先判断错误
int insert(Vector *v, int ind,int val){
    if(ind < 0 || ind > v->length)return 0;
    if(v->length == v->size){
        if(!expand(v)){
            return 0;
        }
    }
    for(int i = v->length - 1;i >= ind;i--){
       v->data[i+1] = v->data[i]; 
    }
    v->data[ind] = val;
    v->length += 1;
    return 1;
}

int erase(Vector *v,int ind){
    if(ind < 0 || ind >= v->length)return 0;
    for(int i = ind+1;i < v->length;i ++){
        v->data[i - 1] = v->data[i];
    }
    v->length --;
    return 1;
}

void output(Vector *v){
    printf("arr=[");
    for(int i = 0;i < v->length;i++){
        printf(" %d",v->data[i]);
    }
    printf("]\n");
    return;
}

int main(){
    #define MAX_OP 20
    int op,ind,val;
    Vector *v;
    v = init(MAX_OP);
    for(int i = 0;i < MAX_OP;i ++){
        op = rand() % 4;
        ind = rand() % (v->length + 3) - 1;
        val = rand() % 100;
        switch(op){
            case 0:
            case 1:
            case 2:{
                printf("insert %d to vector at %d = %d\n"
                       ,val,ind,insert(v,ind,val));
                output(v);
            }break;
            case 3:{
                printf("erase element at %d from vector = %d\n",ind,erase(v,ind));
                output(v);
            }break;
            default: fprintf(stderr,"wrong op %d\n",op);break;
        }
    }
    clear(v);

    return 0;
}
