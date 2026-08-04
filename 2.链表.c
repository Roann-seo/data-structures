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
//单链表尾插法

int main(){
    Node*list=initlist();
    insertHead(list,10);
    insertHead(list,20);
    listNode(list);
    return 1;
}