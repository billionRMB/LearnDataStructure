/*************************************************************************
	> File Name: 1.test.cpp
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年04月10日 星期三 14时55分12秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
typedef struct vector{
    int* data;
    int size,length;
}vector;

vector* init(int n){
    vector * p = (vector*)malloc(sizeof(vector)); 
    p->data = (int*)malloc(sizeof(int)*n);
    p->length = 0;
    p->size = n;
    return p;
}

void clear(vector * v){
    free(v->data);
    free(v);
    return ;
}

int expand(vector *v){
    int size_malloc = v->size;
    int *p;
    while(size_malloc){
        p = (int*)realloc(v->data,sizeof(int)*(v->size + size_malloc));
        if(p)break;
        size_malloc /= 2;
    }
    if(size_malloc == 0)return 0;
    v -> data = p;
    v -> size += size_malloc;
    return 1;
}

int insert(vector *v,int ind,int val){
    if(v->length == v->size){
        if(!expand(v))return 0;
    }
    if(ind < 0 || ind > v->length) return 0;
    for(int i = v->length;i > ind;i --){
        v->data[i] = v->data[i - 1];
    }
    v->data[ind] = val;
    v->length ++;
    return 1;
}

int erase(vector *v,int ind){
    if(ind < 0 || ind >= v->length)return 0;
    for(int i = ind;i < v->length;i ++){
        v->data[i] = v->data[i+1];
    }
    v->length --;
    return 1;
}

void output(vector *v){
    printf("arr=[");
    for(int i = 0;i < v->length;i ++){
        printf(" %d",v->data[i]);
    }
    printf("]\n");
}

int main(){
    #define MAX_OP 20
    int op,ind,val;
    vector *v;
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
