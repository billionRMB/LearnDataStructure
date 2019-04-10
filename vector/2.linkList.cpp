/*************************************************************************
	> File Name: 2.linkList.cpp
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年04月09日 星期二 20时55分00秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>

// 从小的结构开始定义
// 注意结构和结构间可以嵌套的
typedef struct linkListNode{
    int data;
    struct linkListNode *next;
}linkListNode;

// 虚拟头节点 注意一下
typedef struct LinkList{
    linkListNode head; 
    int length;
}linkList;

linkListNode *getNewNode(int val){    
    linkListNode * p = (linkListNode*) malloc(sizeof (linkListNode));
    p->data = val;
    p->next = NULL;
    return p;
}

LinkList* getNewList(){
    LinkList *l = (linkList*)malloc(sizeof(linkList));
    l->head.next = NULL;
    l->length = 0;
    return l;
}

int insert(linkList *l,int ind,int val){
    if(ind < 0 || ind > l->length)return 0;
    linkListNode *p = &(l->head),*new_node = getNewNode(val);
    // 注意　使用ind -- 而不是 --ind
    while(ind --)p = p->next;
    new_node->next = p->next;
    p->next = new_node;
    l->length ++;
    return 1;
    
}

void clear(linkList* l){
    linkListNode * p = l->head.next,*q;
    while(p){
        q = p;
        p = p->next;
        free(q);
    }
    free(l);
    return;
}

int search(linkList *l,int val){
    int ind = 0;
    linkListNode *p = l->head.next;
    while(p && p->data != val) p = p->next,ind +=1;
    if(ind == l->length)return -1;
    return ind;
}

void output(linkList *l){
    printf("head->");
    linkListNode *p = l->head.next;
    while(p){
        printf("%d->",p->data);
        p = p->next;
    }
    printf("null\n");
}

void output_search(LinkList*l,int val){
    if(val == -1)return;
    linkListNode* p = l->head.next;
    printf("      ");int sum = 6;
    for(int i = 0;i < val; i ++){
        int n = p->data;
        while(n)printf(" "),n/=10,sum+=1;
        printf("  "),sum+=2;
        p = p->next;
    }
    printf("^\n");
    while(sum --)printf(" ");
    printf("|\n");
}

int main(){
    LinkList *l = getNewList();
    int ind,val;
    // ｓｃａｎｆ() == 0 是合法的
    // == -1 是非法的 二进制全是1
    // 等价于 while(~scanf("%d%d",&ind,&val))
    while(scanf("%d%d",&ind,&val) != EOF){
        printf("insert %d to linkList at %d = %d\n",val,ind,insert(l,ind,val));
        output(l);
        ind = search(l,val);
        output_search(l,ind);
    }
    return 0;
}
