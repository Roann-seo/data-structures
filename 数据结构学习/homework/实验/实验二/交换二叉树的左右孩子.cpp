#include<iostream>
using namespace std;
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
void swapTree(BiTree T){
    if(T==NULL){
        return;
    }
    BiTNode*temp=T->lchild;
    T->lchild=T->rchild;
    T->rchild=temp;
    swapTree(T->lchild);
    swapTree(T->rchild);
}