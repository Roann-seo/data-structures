//栈的定义
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int Elemtype;
// typedef struct{
//     Elemtype data[MAXSIZE];
//     int top;
// }Stack;
// //初始化
// void initStack(Stack *s){
//     s->top=-1;
// }
//动态内存分配来初始化
typedef struct{
    Elemtype *data;
    int top;
}Stack;
Stack* initStack(){
    Stack*s=(Stack*)malloc(sizeof(Stack*));
    s->data=(Elemtype*)malloc(sizeof(Elemtype)*MAXSIZE);
    s->top=-1;
    return s;
}
//判断栈是否为空
int isEmpty(Stack*s){
    if(s->top==-1){
        printf("空的\n");
        return 0;
    }
    else{
        return 1;
    }
}
//压栈
int push(Stack*s,Elemtype e){
    if(s->top>=MAXSIZE-1){
        printf("满了\n");
        return 0;
    }
    s->top++;
    s->data[s->top]=e;
    return 0;
}
Elemtype pop(Stack*s,Elemtype*e){
    if(s->top==-1){
        printf("空的\n");
        return 0;
    }
    *e=s->data[s->top];
    s->top--;
    return 1;
}
//获取栈顶元素
int getTop(Stack*s,Elemtype *e){
    if(s->top==-1){
        printf("空的\n");
        return 0;
    }
    *e=s->data[s->top];
    return 1;
}
int main(){
    Stack*s=initStack();
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