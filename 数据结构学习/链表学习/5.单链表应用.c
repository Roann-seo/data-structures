// ### 题目【2015，15分】
// 用单链表保存 $n$ 个整数，结点的结构为 $[\text{data}][\text{link}]$，且$|\text{data}|\le n$（$n$ 为正整数）。
//现要求设计一个时间复杂度尽可能高效的算法，对于链表中 data 的绝对值相等的节点，
//仅保留第一次出现的节点而删除其余绝对值相等的节点。

// 例如，若给定单链表 head 如下：
// $\text{head} \to 21 \to -15 \to -15 \to -7 \to 15$

// 删除节点后的 head 为：
// $\text{head} \to 21 \to -15 \to -7$

// **要求：**
// 1）给出算法的基本设计思想。
// 2）使用 C 或 C++ 语言，给出单链表节点的数据类型定义。
// 3）根据设计思想，采用 C 或 C++ 语言描述算法，关键之处给出注释。
// 4）说明你所设计算法的时间复杂度和空间复杂度。

// 用空间换时间
#include<stdio.h>
#include<stdlib.h>
typedef int Elemtype;
typedef struct node{
    struct node*next;
    Elemtype data;
}Node;
Node *initlist(){
    Node*head=(Node*)malloc(sizeof(Node));
    head->data=0;
    head->next=NULL;
    return head;
}
Node* get_tail(Node*L){
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
    tail->next=p;//旧尾节点指向新节点
    return p;
}
void removeNode(Node*L,int n){
    Node*p=L;
    int index;
    int *q=(int *)malloc(sizeof(int)*(n+1));
    for(int i=0;i<n+1;i++){
        *(q+i)=0;
    }
    while(p->next!=NULL){
        index=abs(p->next->data);
        //p 站在待检查节点的前一个，要拿 p->next->data
        if(*(q+index)==0){
            *(q+index)=1;
            p=p->next;
        }else{
            Node*temp=p->next;
            //p 永远站在待检查节点的前一个位置（和链表删除节点逻辑一模一样）
            p->next=temp->next;
            free(temp);
        }
    }
    free(q);
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
    Node *tail=get_tail(list);
    tail=insertTail(tail,21);
    tail=insertTail(tail,-15);
    tail=insertTail(tail,-15);
    tail=insertTail(tail,-7);
    tail=insertTail(tail,15);
    listNode(list);
    removeNode(list,21);
    listNode(list);
    return 0;
}