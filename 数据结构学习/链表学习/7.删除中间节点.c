#include<stdio.h>
#include<stdlib.h>
typedef int Elemtype;
typedef struct node{
    Elemtype data;
    struct node* next;
}Node;
Node*initlist(){
    Node*head=(Node*)malloc(sizeof(Node));
    head->data=0;
    head->next=NULL;
    return head;
}
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
    p->next=NULL;
    tail->next=p;
    return p;
}
int delmiddle(Node*head){
    Node*fast=head->next;
    Node*slow=head;
    while(fast->next!=NULL&&fast->next->next!=NULL){
//fast 不为空，并且 fast 下一个节点也不为空，才允许跳两步，防止fast->next->next空指针。
        fast=fast->next->next;
        slow=slow->next;
    }
    Node*q=slow->next;
    slow->next=q->next;
    free(q);
    return 1;
}
void Nodelist(Node*L){
    Node*p=L->next;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main(){
    Node*list=initlist();
    Node*tail=get_tail(list);
    tail=insertTail(tail,1);
    tail=insertTail(tail,2);
    tail=insertTail(tail,3);
    tail=insertTail(tail,4);
    tail=insertTail(tail,5);
    tail=insertTail(tail,6);
    tail=insertTail(tail,7);
    Nodelist(list);
    delmiddle(list);
    Nodelist(list);
    return 0;
}