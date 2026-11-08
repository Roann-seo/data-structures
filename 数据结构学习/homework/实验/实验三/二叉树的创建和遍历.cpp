#include<iostream>
#define MAXSIZE 100
using namespace std;
//二叉树的二叉链表存储表示
typedef struct BiNode{
    char data;
    BiNode*lchild,*rchild;
}BiNode,*BiTree;
//用递归方法建立二叉链表
void CreateBiTree(BiTree &T)
{
    //按先序次序输入二叉树中结点的值（一个字符）
    //创建二叉链表表示的二叉树T
    char ch;
    cin>>ch;
    if(ch=='#'){
        T=NULL;
    }
    else{
        T=new BiNode;
        T->data=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

 //求二叉树T的深度
void HeightBiTree(BiTree T, int &height)
{
    /*――――递归方法计算二叉树T的深度，保存在height中――――*/
    if(T==NULL){
        height=0;
        return;
    }
    int hl,hr;
    HeightBiTree(T->lchild,hl);
    HeightBiTree(T->rchild,hr);
    height=max(hl,hr)+1;
}

 //中序遍历的方式输出T中各元素
void InOrderTraverse(BiTree T)
{
    /*―――递归方法中序遍历二叉树各结点，并输出结点数据―――*/
    if(T==NULL){
        return ;
    }
    InOrderTraverse(T->lchild);
    cout<<T->data;
    InOrderTraverse(T->rchild);
}
//二叉树的层次遍历(利用队列)
typedef struct {
    BiTree *data;
    int front;
    int rear;
}Queue;
void initQueue(Queue *q){
    q->front=q->rear=0;
}
bool isfull(Queue*Q){
    if((Q->rear+1)%MAXSIZE==Q->front){
        return 1;
    }
    return 0;
}
bool isempty(Queue*Q){
    if(Q->front==Q->rear){
        return 1;
    }
    return 0;
}
void EnQueue(Queue*Q,BiTree T){
    if(isfull(Q)){
        cout<<"满了";
    }
    Q->rear[Q->data]=T;
    Q->rear=(Q->rear+1)%MAXSIZE;
}
void DeQueue(Queue*Q,BiTree& T){
    if(isempty(Q)){
        cout<<"空的";
    }
    T= Q->data[Q->front];
    Q->front=(Q->front+1)%MAXSIZE;
}
void Level_Traverse(BiTree T){
    Queue *Q;
    initQueue(Q);//先创建一个队列
    if(T!=NULL){
        EnQueue(Q,T);
    }
    while(!isempty(Q)){
        BiTree u;
        DeQueue(Q,u);
        cout<<u;
        if(u->lchild!=NULL){
            EnQueue(Q,u->lchild);
        }
        if(u->rchild!=NULL){
            EnQueue(Q,u->rchild);
        }
    }
}
int main(){
    BiTree tree;
    int height;
    cout<<"请输入建立二叉树的序列:\n";
    CreateBiTree(tree);
    HeightBiTree(tree,height);
    cout<<"二叉树的高度为:"<<height<<endl;
    InOrderTraverse(tree);
    cout<<endl;
    return 0;
}