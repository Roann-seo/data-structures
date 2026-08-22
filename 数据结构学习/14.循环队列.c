#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int Elemtype;
typedef struct {
    Elemtype *data;
    int front;
    int rear;
}Queue;
Queue*initqueue(){
    Queue*q=(Queue*)malloc(sizeof(Queue));
    q->data=(Elemtype*)malloc(sizeof(Elemtype)*MAXSIZE);
    q->front=0;
    q->rear=0;
    return q;
}
//入队
int equeue(Queue*q,Elemtype e){
    if((q->rear+1)%MAXSIZE==q->front){
        printf("满了\n");
        return 0;
    }
    q->rear[q->data]=e;
    q->rear=(q->rear+1)%MAXSIZE;
    return 1;
}
//出队
int dequeue(Queue*q,Elemtype *e){
    if(q->front==q->rear){
        printf("空的\n");
        return 0;
    }
    *e=q->data[q->front];
    q->front=(q->front+1)%MAXSIZE;
    return 1;
}
//获取队头元素
int gethead(Queue*q,Elemtype *e){
    if(q->front==q->rear){
        printf("空了\n");
        return 0;
    }
    *e=q->data[q->front];
    return 1;
}
int main(){
    Queue *q=initqueue();
    equeue(q,10);
    equeue(q,20);
    equeue(q,30);
    equeue(q,40);
    equeue(q,50);
    
    Elemtype e;
    dequeue(q,&e);
    printf("%d\n",e);
    dequeue(q,&e);
    printf("%d\n",e);
    gethead(q,&e);
    printf("%d\n",e);
    return 0;
}