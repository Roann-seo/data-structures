#include<iostream>
#include<stack>
#include<vector>
#define max 100
using namespace std;
typedef struct {
    char *data;
    int front;
    int rear;
    int maxsize;
}Queue;
//创建队列
Queue*createqueue(int size){
    Queue*q=new Queue;
    q->data=new char[size+1];
    q->front=q->rear=0;
    q->maxsize=size;
    return q;
}
//判断队列是否为空
bool isempty(Queue*q){
    if(q->front==q->rear){
        return 1;//为空
    }else{
        return 0;//不为空
    }
}
bool isfull(Queue*q){
    if((q->rear+1)%q->maxsize==q->front){
        return 1;//满了
    }else{
        return 0;//没有满
    }
}
bool enqueue(Queue*q,char c){
    if(isfull(q)){
        return false;
    }
    q->data[q->rear]=c;
    q->rear=(q->rear+1)%q->maxsize;
    q->maxsize++;
    return true;
}
bool dequeue(Queue*q,char&c){
    if(isempty(q)){
        return false;
    }
    c=q->data[q->front];
    q->front=(q->front+1)%q->maxsize;
    q->maxsize--;
    return true;
}
typedef struct stack{
    char data[max];
    int top;
    int maxsize;
}Stack;
//创建栈
Stack*createstack(int size){
    Stack*s=new Stack;
    char* data=new char[size+1];
    s->top=-1;
    s->maxsize=size;
    return s;
}
//判断栈是否为空
bool stackempty(Stack*s){
    if(s->top==-1){
        return 1;//空的
    }else{
        return 0;
    }
}
bool stackfull(Stack*s){
    if(s->top==s->maxsize-1){
        return 1;//满了
    }else{
        return 0;
    }
}
bool push(Stack*s,char c){
    if(stackfull(s)){
        return false;
    }
    s->top++;
    s->data[s->top]=c;
    return true;
}
bool pop(Stack*s,char &c){
    if(stackempty(s)){
        return false;
    }
    c=s->data[s->top--];
    return true;
}
Queue*qs[1005];
int main(){
    int N,M,Smax;
    cin>>N>>M>>Smax;
    for(int i=0;i<N;i++){
        qs[i]=createqueue(M);
        char ch;
        for(int j=0;j<M;j++){
            cin>>ch;
            enqueue(qs[i],ch);
        }
    }
    Stack*basket=createstack(Smax);
    string res;
    int op;
    while(cin>>op,op!=-1){
        if(op==0){
            if(basket->top!=-1){
                char ch;
                pop(basket,ch);
                res+=ch;
            }
            continue;
        }else{
            int idx=op-1;
            if(stackfull(basket)){
                char ch;
                pop(basket,ch);
                res+=ch;
            }else{
                char ch;
                dequeue(qs[idx],ch);
                push(basket,ch);
            }
        }
    }
    cout<<res<<endl;
    return 0;
}