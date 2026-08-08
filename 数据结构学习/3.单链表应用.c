// ### ［2019］（15分）
// 已知一个带有表头节点的单链表，节点结构为

// | data | link |
// |------|------|

// 假设该链表只给出了头指针`list`。在不改变链表的前提下，请设计一个尽可能高效的算法，查找链表中倒数第k个位置上的结点（k为正整数）。若查找成功，算法输出该节点的data域的值，并返回1；否则，只返回0。要求：
// 1）描述算法的基本思想；
// 2）描述算法的详细实现步骤；
// 3）根据设计思想和实现步骤，采用程序设计语言描述算法（使用C、C++、或Java语言实现），关键之处请给出简要注释。
#include<stdio.h>
#include<stdlib.h>
//使用双指针找到倒数第k个节点
typedef int Elemtype;
typedef struct node{
    Elemtype data;
    struct node *next;
}Node;
int findNodeFS(Node*L,int k){
    Node*fast=L->next;
    Node*slow=L->next;
    for(int i=0;i<k;i++){
        fast=fast->next;
        if(fast==NULL){
            printf("要查找的位置错误\n");
            return 0;
        }
    }
    while(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    printf("第%d位置的数据是%d\n",k,slow->data);
    return 1;
}
Node*initList(){
    Node*head=(Node*)malloc(sizeof(Node));
    head->data=0;
    head->next=NULL;
    return head;
}
Node* get_Tail(Node*L){
    Node*p=L;
    while(p->next!=NULL){
        p=p->next;
    }
    return p;
}
Node* insertTail(Node*Tail,Elemtype e){
    Node*p=(Node*)malloc(sizeof(Node));
    p->data=e;
    Tail->next=p;
    p->next=NULL;
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
int main(){
    Node*list=initList();
    Node*tail=get_Tail(list);
    tail=insertTail(tail,10);
    tail=insertTail(tail,20);
    tail=insertTail(tail,30);
    tail=insertTail(tail,40);
    tail=insertTail(tail,50);
    tail=insertTail(tail,60);
    tail=insertTail(tail,70);
    listNode(list);
    findNodeFS(list,3);
}