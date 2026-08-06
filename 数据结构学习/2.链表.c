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
//单链表尾插法//找到尾节点
Node* get_tail(Node* L){
    Node*p=L;
    while(p->next!=NULL){
        p=p->next;
    }
    return p;
}
Node *insertTail(Node* Tail,ElemType e){
    Node*p=(Node*)malloc(sizeof(Node));
    p->data=e;
    Tail->next=p;
    p->next=NULL;
    return p;//返回新的尾节点
}
//在指定位置插入数据
int insertNode(Node*L,int pos,ElemType e){
    Node *p=L;//找到前驱节点
    int i=0;
    while(i<pos-1){
        p=p->next;
        i++;
        if(p==NULL){
            return 0;
        }
    }
    Node*q=(Node*)malloc(sizeof(Node));
    q->data=e;
    q->next=p->next;
    p->next=q;
    return 0;
}
//在指定位置删除数据
int deleteNode(Node*L,int pos){
    Node* p=L;
    int i=0;
    while(i<pos-1){
        p=p->next;
        i++;
    }//p是要删除位置的前一个元素
    if(p->next==NULL){
        printf("要删除位置错误\n");
        return 0;
    }
    Node* q=p->next;//q是要删除的元素
    p->next=q->next;
    //printf("被删除的数据%d\n",q->data);
    free(q);
    return 1;
}
//获取链表长度
int listlength(Node*L){
    Node*p=L;
    int len=0;
    while(p->next!=NULL){
        p=p->next;
        len++;
    }
    return len;
}
//释放链表
void freelist(Node*L){
    Node* p=L->next;
    Node*q;
    while(p->next!=NULL){
        q=p->next;
        free(p);
        p=q;
    }
    L->next=NULL;
}
int main(){
    Node*list=initlist();
    // insertHead(list,10);
    // insertHead(list,20);
    Node*Tail=get_tail(list);
    Tail=insertTail(Tail,10);
    Tail=insertTail(Tail,20);
    Tail=insertTail(Tail,30);
    listNode(list);
    insertNode(list,2,15);
    listNode(list);
    deleteNode(list,2);
    listNode(list);
    printf("释放之前链表长度%d\n",listlength(list));
    freelist(list);
    printf("释放之后链表长度%d\n",listlength(list));
    return 1;
}