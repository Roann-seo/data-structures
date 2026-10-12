// 设计算法将一个带头结点的单链表A分解为两个具有相同结构的链表B、C,
// 其中B表的结点为A表中值小于零的结点,而C表的结点为A表中值大于零的结点
// (链表A中的元素为非零整数,要求B、C表利用A表的结点)。
#include<stdio.h>
typedef int Elemtype;
typedef struct node{
    Elemtype data;
    struct node*next;
}Node;
Node*breaknode(Node*a,Node*b,Node*c){
    Node*pa=a->next;
    Node*pb=b;
    Node*pc=c;
    while(pa!=NULL){
        if(pa->data>0){
            pc->next=pa;
            pc=pc->next;
        }else if(pa->data<0){
            pb->next=pa;
            pb=pb->next;
        }
        pa=pa->next;
    }
    pb->next=NULL;
    pc->next=NULL;
    return a;
}