// 将两个非递减的有序链表合并为一个非递增的有序链表。
// 要求结果链表仍使用原来两个链表的存储空间, 不另外占用其它的存储空间。
// 表中允许有重复的数据。
#include<stdio.h>
typedef int Elemtype;
typedef struct node{
    Elemtype data;
    struct node*next;
}Node;
Node* mergelist(Node *a,Node*b,Node*c){
    Node*pa=a->next;
    Node*pb=b->next;
    Node*pc;
    c->next=NULL;
    while(pa!=NULL&&pb!=NULL){
        if(pa->data<pb->data){
            pc=pa;
            pa=pa->next;
        }else{
            pc=pb;
            pb=pb->next;
        }
        pc->next=c->next;
        c->next=pc;//头插法
    }
    if(pa!=NULL){
        pc=pa;
        pa=pa->next;//注意pa先移动？？
        pc->next=c->next;
        c->next=pc;
    }
    if(pb!=NULL){
        pc=pb;
        pb=pb->next;
        pc->next=c->next;
        c->next=pc;
    }
    return c;
}