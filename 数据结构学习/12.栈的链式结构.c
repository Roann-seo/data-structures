#include<stdio.h>
#include<stdlib.h>
typedef int Elemtype;
typedef struct stack{
    Elemtype data;
    struct stack*next;
}Stack;
Stack*initStack(){
    Stack*s=(Stack*)malloc(sizeof(Stack));
    s->data=0;
    s->next=NULL;
    return s;
}
int isempty(Stack*s){
    if(s->next==NULL){
        printf("空的\n");
        return 1;
    }else{
        return 0;
    }
}
//压栈
int push(Stack*s,Elemtype e){
    Stack*p=(Stack*)malloc(sizeof(Stack));
    p->data=e;
    p->next=s->next;
    s->next=p;
    return 1;
}
//出栈
int pop(Stack*s,Elemtype *e){
    if(s->next==NULL){
        printf("空的\n");
        return 0;
    }
    *e=s->next->data;
    Stack*q=s->next;
    s->next=q->next;
    free(q);
    return 0;
}
//获取栈顶元素
int getTop(Stack*s,Elemtype *e){
    if(s->next==NULL){
        printf("空的\n");
        return 0;
    }
    *e=s->next->data;
    return 1;
}
int main(){
    Stack *s=initStack();
    push(s,10);
    push(s,20);
    push(s,30);
    Elemtype e;
    pop(s,&e);
    printf("%d\n",e);
    getTop(s,&e);
    printf("%d\n",e);
    return 0;
}