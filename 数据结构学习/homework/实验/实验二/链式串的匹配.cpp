// s、t 都是**单链表存储的串**（链式串，一个结点存一个字符）；
// 功能：找到 s 里**第一个和 t 完全匹配的连续子串**，把这一段链表结点逆置；
// 如果 t 不是 s 的子串，什么都不做。
#include<iostream>
using namespace std;
typedef struct node{
    int data;
    struct node*next;
}Node;
int length(Node *s){
    int cnt=0;
    Node*p=s;
    while(p!=nullptr){
        p=p->next;
        cnt++;
    }
    return cnt;
}
Node* reversenode(Node*s,Node*end_next){
    Node*first=nullptr;
    Node*second=s;
    Node*third;
    while(second!=end_next){
        third=second->next;
        second->next=first;
        first=second;
        second=third;
    }
    return first;
}
bool BF(Node*s,Node* t,Node*&start,Node*&pre,Node*&end_next){
    start=s;
    pre=nullptr;//记录主串起始结点的前驱结点,如果第一次匹配失败，pre里面就是脏值，pre->next直接崩
    int longs=length(s);
    int longt=length(t);
    Node*p=start;
    Node*q=t;
    while(p!=nullptr&&q!=nullptr){
        if(p->data==q->data){
            p=p->next;
            q=q->next;
        }else{
            pre=start;
            start=start->next;//否则将主串起始值往后移动一位
            p=start;
            q=t;
        }
    }
    if(q==nullptr){
        end_next=p;
        return true;//找到了
    }else{
        return false;
    }
}
Node*reservematch(Node*s,Node*t){
    Node*start;
    Node*pre;
    Node*end_next;
    bool ok=BF(s,t,start,pre,end_next);
    Node*newpart;
    if(ok){
        newpart=reversenode(start,end_next);
        pre->next=newpart;
        start->next=end_next;
    }
    return s;
}
