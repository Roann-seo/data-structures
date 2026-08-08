#include<stdio.h>
#include<stdlib.h>
typedef int Elemtype;
typedef struct node{
    Elemtype data;
    struct node*next;
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
Node*insertNode(Node* tail,Elemtype e){
    Node*p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->next=NULL;
    tail->next=p;
    return p;
}
void listNode(Node*L){
    Node*p=L->next;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
Node*reverseList(Node* head){
    Node*first=NULL;
    Node*second=head->next;
    Node*third;
    while(second!=NULL){
        third=second->next;
        second->next=first;
        first=second;
        second=third;
    }
    Node*hd=initlist();
    hd->next=first;
    return hd;
}
int main(){
    Node*list=initlist();
    Node*tail=get_tail(list);
    tail=insertNode(tail,1);
    tail=insertNode(tail,2);
    tail=insertNode(tail,3);
    tail=insertNode(tail,4);
    tail=insertNode(tail,5);
    tail=insertNode(tail,6);
    listNode(list);
    Node*reverse=reverseList(list);
    listNode(reverse);
    return 0;
}