#include<iostream>
using namespace std;
typedef struct BiNode{
    int data;
    struct BiNode*lchild,*rchild;
}BiNode,*BiTree;
void createBiTree(BiTree &T){
    int val;
    cin>>val;
    while(val==-1){
        T=NULL;
        return ;
    }
    T=new BiNode;
    T->data=val;
    createBiTree(T->lchild);
    createBiTree(T->rchild);
}//先序
void preorder(BiTree T){
    if(T==NULL){
        return ;
    }
    cout<<T->data<<" ";
    preorder(T->lchild);
    preorder(T->rchild);
}
void inorder(BiTree T){
    if(T==NULL){
        return ;
    }
    inorder(T->lchild);
    cout<<T->data<<" ";
    inorder(T->rchild);
}
void postorder(BiTree T){
    if(T==NULL){
        return ;
    }
    postorder(T->lchild);
    postorder(T->rchild);
    cout<<T->data<<" ";
}
int main()
{
    BiTree T;
    cout << "请按先序输入节点值，-1为空节点：\n";
    createBiTree(T);

    cout << "先序遍历：";
    preorder(T);
    cout << "\n";

    cout << "中序遍历：";
    inorder(T);
    cout << "\n";

    cout << "后序遍历：";
    postorder(T);
    cout << "\n";
    return 0;
}