#include<stdio.h>
#include<stdlib.h>
typedef int Elemtype;
typedef struct node{
    Elemtype data;
    struct node*prev,*next;
}Node;
//初始化链表
Node*initlist(){
    Node*head=(Node*)malloc(sizeof(Node));
    head->data=0;
    head->next=NULL;
    head->prev=NULL;
    return head;
}
//双向链表头插法
int insertHead(Node*L,Elemtype e){
    Node*p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->prev=L;
    p->next=L->next;
    if(L->next!=NULL){
        L->next->prev=p;
    }
    L->next=p;
    return 1;
}
//双向链表尾插法
Node*get_tail(Node*L){
    Node*p=L;
    while(p->next!=NULL){
        p=p->next;
    }
    return p;
}
Node*insertTail(Node*tail,Elemtype e){
    Node*p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->prev=tail;
    tail->next=p;
    p->next=NULL;
    return p;
}
//在指定位置插入数据
int insertNode(Node*L,int pos,Elemtype e){
    Node*p=L;
    int i=0;
    while(i<pos){
        p=p->next;
        i++;
        if(p==NULL){
            return 0;
        }
    }
    Node*q=(Node*)malloc(sizeof(Node));
    q->data=e;
    q->prev=p;
    q->next=p->next;
    if(p->next!=NULL){
        p->next->prev=q;
    }
    p->next=q;
    return 1;
}
//遍历双向链表
void listNode(Node*L){
    Node*p=L->next;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main(){
    Node*list=initlist();
    insertHead(list,10);
    insertHead(list,20);
    insertHead(list,30);
    //listNode(list);
    Node*tail=get_tail(list);
    tail=insertTail(tail,10);
    tail=insertTail(tail,20);
    tail=insertTail(tail,30);
    //listNode(list);
    insertNode(list,2,15);
    listNode(list);
    return 0;
}