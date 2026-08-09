// 题目[2019]（13 分）
// 设线性表\(\boldsymbol{L=(a_1,a_2,a_3,\dots,a_{n-2},a_{n-1},a_n)}\)
// 采用带头结点的单链表保存，链表中的节点定义如下：
// typedef struct node
// {
//     int data;
//     struct node* next;
// }NODE;
// 请设计一个空间复杂度为\(O(1)\)且时间上尽可能高效的算法，
// 重新排列 L 中的各节点，得到线性表\(\boldsymbol{L'=(a_1,a_n,a_2,a_{n-1},a_3,a_{n-2},\dots)}\)。要求：
// 1）给出算法的基本设计思想。
// 2）根据设计思想，采用 C 或 C++ 语言描述算法，关键之处给出注释。
// 3）说明你所设计算法的时间复杂度。
//示例：输入1 2 3 4 5 6，输出1 6 2 5 3 4
#include<stdio.h>
#include<stdlib.h>
typedef int Elemtype;
typedef struct node{
    int data;
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
Node*insertTail(Node*tail,Elemtype e){
    Node*p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->next=NULL;
    tail->next=p;
    return p;
}
void reorderlist(Node*L){
    if(L->next==NULL||L->next->next==NULL){
        return;
    }
    //当要反转的是偶数个节点时
    Node*fast=L;
    Node*slow=L;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    //当要反转的是奇数个节点时
    // Node*fast=L->next;
    // Node*slow=L;
    // while(fast->next!=NULL&&fast->next->next!=NULL){
    //     fast=fast->next->next;
    //     slow=slow->next;
    // }
    Node*first=NULL;
    Node*second=slow->next;
    slow->next=NULL;
    Node*third=NULL;
    while(second!=NULL){
        third=second->next;
        second->next=first;
        first=second;
        second=third;
    }
    Node*p1=L->next;
    Node*q1=first;
    Node*p2;
    Node*q2;
    while(p1!=NULL&&q1!=NULL){
        p2=p1->next;
        q2=q1->next;
        p1->next=q1;
        q1->next=p2;
        p1=p2;
        q1=q2;
    }
}
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
    Node*tail=get_tail(list);
    tail=insertTail(tail,1);
    tail=insertTail(tail,2);
    tail=insertTail(tail,3);
    tail=insertTail(tail,4);
    tail=insertTail(tail,5);
    tail=insertTail(tail,6);
    listNode(list);
    reorderlist(list);
    listNode(list);
    return 0;
}