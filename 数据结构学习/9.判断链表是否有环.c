//单向循环链表
//单链表中判别条件为p!=NULL或者p->next!=NULL
//循环链表判别条件为p!=L||p->next!=L
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
Node*get_Tail(Node*L){
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
//判断链表是否有环
int iscycle(Node*head){
    Node*fast=head;
    Node*slow=head;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return 1;
        }
    }
    return 0;
}
//判断环的入口
Node*findbegin(Node*head){
    Node*fast=head;
    Node*slow=head;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            Node*p=fast;
            int count=1;
            while(p->next!=slow){
                p=p->next;
                count++;
            }
            fast=head;
            slow=head;
            for(int i=0;i<count;i++){
                fast=fast->next;
            }
            while(fast!=slow){
                fast=fast->next;
                slow=slow->next;
            }
            return slow;
        }
    }
    return NULL;
}
int main(){
    Node*list=initlist();
    Node*tail=get_Tail(list);
    tail=insertTail(tail,1);
    tail=insertTail(tail,2);
    tail=insertTail(tail,3);
    Node*three=tail;
    tail=insertTail(tail,4); 
    tail=insertTail(tail,5);
    tail=insertTail(tail,6);
    tail=insertTail(tail,7);
    tail=insertTail(tail,8);
    tail->next=three;
    if(iscycle(list)){
        printf("有环\n");
        printf("环的起点是%d\n",findbegin(list)->data);
    }else{
        printf("无环\n");
    }
    return 0;
}