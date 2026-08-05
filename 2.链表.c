#include<stdio.h>
#include<stdlib.h>//这个是malloc的头文件
typedef int ElemType;
typedef struct node{
    ElemType data;
    struct node *next;
}Node;
//单链表初始化
Node*initlist(){
    Node*head=(Node*)malloc(sizeof(Node));
    head->data=0;
    head->next=NULL;
    return head;
}
//单链表头插法
int insertHead(Node* L,ElemType e){
    Node*p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->next=L->next;
    L->next=p;
    return 1;
}
//单链表遍历
void listNode(Node*L){
    Node*p=L->next;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
//单链表尾插法//找到尾节点
Node* get_tail(Node* L){
    Node*p=L;
    while(p->next!=NULL){
        p=p->next;
    }
    return p;
}
Node *insertTail(Node* Tail,ElemType e){
    Node*p=(Node*)malloc(sizeof(Node));
    p->data=e;
    Tail->next=p;
    p->next=NULL;
    return p;//返回新的尾节点
}
//在指定位置插入数据
int insertNode(Node*L,int pos,ElemType e){
    Node *p=L;//找到前驱节点
    int i=0;
    while(i<pos-1){
        p=p->next;
        i++;
        if(p==NULL){
            return 0;
        }
    }
    Node*q=(Node*)malloc(sizeof(Node));
    q->data=e;
    q->next=p->next;
    p->next=q;
    return 0;
}
int main(){
    Node*list=initlist();
    // insertHead(list,10);
    // insertHead(list,20);
    Node*Tail=get_tail(list);
    Tail=insertTail(Tail,10);
    Tail=insertTail(Tail,20);
    Tail=insertTail(Tail,30);
    listNode(list);
    insertNode(list,2,15);
    listNode(list);
    return 1;
}