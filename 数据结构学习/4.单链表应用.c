// 求两个单链表公共后缀起始结点
// 题目：两个带头结点单链表str1、str2，找出公共后缀第一个结点，没有公共后缀返回NULL。
// 1）算法基本设计思想 📌
// 分别遍历两个链表，求出链表str1长度len1，链表str2长度len2。
// 将两个链表尾部对齐：长链表的指针先向前移动长度差值步，使得两个指针到链表尾部的结点数量相等。
// 两个指针同步向后逐个移动，每一轮比较两个指针是否指向同一个结点地址。
// 第一次遇到地址相等的结点，就是公共后缀的起始结点，返回该结点；循环结束没找到返回NULL。
// 💡注意：不是比较 data 数据，是比较结点地址！ 题目是内存共享后缀，相同的内存结点，不是单纯字符相同。
#include<stdio.h>
#include<stdlib.h>
typedef char Elemtype;
typedef struct node{
    Elemtype data;
    struct node*next;
}Node;
Node* initlist(){
    Node*head=(Node*)malloc(sizeof(Node));
    head->data=0;
    head->next=NULL;
    return head;
}
//初始化节点（带节点数据域参数）
Node* initListWithElem(Elemtype e){
    Node* node=(Node*)malloc(sizeof(Node));
    node->data=e;
    node->next=NULL;
    return node;
}
Node* get_tail(Node*L){
    Node*p=L;
    while(p->next!=NULL){
        p=p->next;
    }
    return p;
}
Node*insertTail(Node*Tail,Elemtype e){
    Node*p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->next=NULL;
    Tail->next=p;
    return p;
}
//尾插法 节点
Node* insertTailWithNode(Node *tail,Node *node){
    tail->next=node;
    node->next=NULL;
    return node;
}
void listNode(Node*L){
    Node*p=L->next;
    while(p!=NULL){
        printf("%c ",p->data);
        p=p->next;
    }
    printf("\n");
}
Node* findIntersectionNode(Node *headA,Node *headB){
    if(headA==NULL||headB==NULL){
        return NULL;
    }
    Node*p=headA;
    int lenA=0;
    int lenB=0;
    while(p!=NULL){
        p=p->next;
        lenA++;
    }
    p=headB;
    while(p!=NULL){
        p=p->next;
        lenB++;
    }
    int step=0;
    Node*fast;
    Node*slow;
    if(lenA>lenB){
        step=lenA-lenB;
        fast=headA;
        slow=headB;
    }else{
        step=lenB-lenA;
        fast=headB;
        slow=headA;
    }
    for(int i=0;i<step;i++){
        fast=fast->next;
    }
    while(fast!=slow){
        fast=fast->next;
        slow=slow->next;
    }
    return fast;
}
int main(){
    Node *listA=initlist();
    Node *listB=initlist();
    Node *tailA=get_tail(listA);
    Node *tailB=get_tail(listB);
    tailA=insertTail(tailA,'l');
    tailA=insertTail(tailA,'o');
    tailA=insertTail(tailA,'a');
    tailA=insertTail(tailA,'d');
    tailB=insertTail(tailB,'b');
    tailB=insertTail(tailB,'e');
    Node* nodeI=initListWithElem('i');
    tailA=insertTailWithNode(tailA,nodeI);
    tailB=insertTailWithNode(tailB,nodeI);
    Node* nodeN=initListWithElem('n');
    tailA=insertTailWithNode(tailA,nodeN);
    tailB=insertTailWithNode(tailB,nodeN);
    Node* nodeG=initListWithElem('g');
    tailA=insertTailWithNode(tailA,nodeG);
    tailB=insertTailWithNode(tailB,nodeG);
    listNode(listA);
    listNode(listB);
    printf("%c\n",findIntersectionNode(listA,listB)->data);
    return 0;
}