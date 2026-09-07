// **题目**：单链表 + pivot 值，把链表划分成三部分：
// `[小于pivot] -> [等于pivot] -> [大于pivot]`，
// **不能开数组，O (1) 额外空间**，保持原有相对顺序（稳定分区）
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int val;
    struct node*next;
}Node;
Node*listPartition(Node*head,int pivot){
    Node*sh=NULL;
    Node*st=NULL;
    Node*eh=NULL;
    Node*et=NULL;
    Node*mh=NULL;
    Node*mt=NULL;
    Node*next=NULL;
    while(head!=NULL){
        next=head->next;
        head->next=NULL;
        if(head->val<pivot){
            if(sh==NULL){
                sh=head;
                st=head;
            }else{
                st->next=head;
                st=head;
            }
        }else if(head->val==pivot){
            if(eh==NULL){
                eh=head;
                et=head;
            }else{
                et->next=head;
                et=head;
            }
        }else{
            if(mh==NULL){
                mh=head;
                mt=head;
            }else{
                mt->next=head;
                mt=head;
            }
        }
        head=next;
    }
    if(st!=NULL){
        st->next=eh;
        et=(et==NULL)?st:et;
    }
    if(et!=NULL){
        et->next=mh;
    }
    if(sh!=NULL){
        return sh;
    }else if(eh!=NULL){
        return eh;
    }else{
        return mt;
    }
}
Node* createNode(int v){
    Node*p=(Node*)malloc(sizeof(Node));
    p->val=v;
    p->next=NULL;
    return p;
}
void printList(Node* head){
    while(head!=NULL){
        printf("%d ",head->val);
        head=head->next;
    }
    printf("\n");
}
int main(void)
{
    //测试链表：3 1 4 2 5 2  pivot=2
    Node* h = createNode(3);
    h->next = createNode(1);
    h->next->next = createNode(4);
    h->next->next->next = createNode(2);
    h->next->next->next->next = createNode(5);
    h->next->next->next->next->next = createNode(2);

    Node* res = listPartition(h, 2);
    printList(res);
    //输出结果：1 2 2 3 4 5
    return 0;
}