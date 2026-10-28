#include<stdio.h>
#include<stdlib.h>
typedef int SElemType;
typedef struct{
    int bot[2]; //栈顶指针
    SElemType *V; //栈数组
    int m; //栈最大可容纳元素个数
}DblStack;
int InitDblStack(DblStack*s,int m){
    s->V=(SElemType*)malloc(sizeof(SElemType)*m);
    if(!s->V){
        return 0;
    }
    s->m=m;
    s->bot[0]=-1;
    s->bot[1]=m;
    return 1;
}
int isempty(DblStack*s,int i){
    if(i==0){
        if(s->bot[0]==-1){
            return 1;
        }else{
            return 0;
        }
    }else{
        if(s->bot[1]==s->m){
            return 1;
        }else{
            return 0;
        }
    }
}
int isfull(DblStack*s){
    if(s->bot[0]+1==s->bot[1]){
        return 1;
    }
    return 0;
}
int Push(DblStack*s,int i,SElemType e){
    if(isfull(s)){
        return 0;
    }
    if(i==0){
        s->bot[0]++;
        s->V[s->bot[0]]=e;
    }else if(i==1){
        s->bot[1]--;
        s->V[s->bot[1]]=e;
    }else{
        return 0;
    }
    return 1;
}
int Pop(DblStack*s,int i,SElemType*e){
    if(isempty(s,i)){
        return 0;
    }
    if(i==0){
        *e=s->V[s->bot[0]];
        s->bot[0]--;
    }else if(i==1){
        *e=s->V[s->bot[1]];
        s->bot[1]++;
    }else{
        return 0;
    }
    return 1;
}
int main()
{
    DblStack ds;
    SElemType x;
    InitDblStack(&ds, 10); //数组容量m=10

    Push(&ds,0,10);
    Push(&ds,0,20);
    Push(&ds,1,90);
    Push(&ds,1,80);

    Pop(&ds,0,&x); printf("栈0弹出：%d\n",x);
    Pop(&ds,1,&x); printf("栈1弹出：%d\n",x);
    return 0;
}