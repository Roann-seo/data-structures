#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int Elemtype;
typedef struct{
    Elemtype data[MAXSIZE];
    int front;
    int rear;
}Queue;
//初始化
void initQueue(Queue*q){
    q->front=0;
    q->rear=0;
}
//判断队列是否为空
int isempty(Queue *q){
    if(q->front==q->rear){
        printf("队列为空\n");
        return 1;
    }
    else{
        return 0;
    }
}
//出队
Elemtype dequeue(Queue *q){
    if(q->front==q->rear){
        printf("空的\n");
        return 0;
    }
    Elemtype e=q->data[q->front];
    q->front++;
    return e;
}
//入队
int queueFull(Queue*q){
    if(q->front>0){
        int step=q->front;
        for(int i=q->front;i<q->rear;i++){
            q->data[i-step]=q->data[i];
        }
        q->front=0;
        q->rear=q->rear-step;
        return 1;
    }else{
        printf("满了\n");
        return 0;
    }

}
int equeue(Queue *q,Elemtype e){
    if(q->rear>=MAXSIZE){
        if(!queueFull(q)){
            return 1;
        }
    }
    q->data[q->rear]=e;
    q->rear++;
    return 1;
}
//获取队头数据
int getHead(Queue*q,Elemtype *e){
    if(q->front==q->rear){
        printf("空了\n");
        return 0;
    }
    *e=q->data[q->front];
    return 1;
}
int main(){
    Queue q;
    initQueue(&q);
    equeue(&q,10);
    equeue(&q,20);
    equeue(&q,30);
    equeue(&q,40);
    equeue(&q,50);
    printf("%d\n",dequeue(&q));
    printf("%d\n",dequeue(&q));
    Elemtype e;
    getHead(&q,&e);
    printf("%d\n",e);
    return 0;
}