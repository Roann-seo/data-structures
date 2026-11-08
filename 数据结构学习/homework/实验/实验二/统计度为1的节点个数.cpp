#include<iostream>
using namespace std;
typedef struct BiTNode{
    char data;
    struct BiTNode*lchild,*rchild;
}BiTNode,*BiTree;
int countDegree1(BiTree T){
    if(T==NULL){
        return 0;
    }
    BiTNode*Q[100];
    int rear=0;
    int front=0;
    Q[rear++]=T;
    int cnt=0;
    while(front<rear){
        BiTNode*p=Q[front++];
        if((p->lchild==NULL&&p->rchild!=NULL)||(p->lchild!=NULL&&p->rchild==NULL)){
            cnt++;
        }
        if(p->lchild){
            Q[rear++]=p->lchild;
        }
        if(p->rchild){
            Q[rear++]=p->rchild;
        }
    }
    return cnt;
}