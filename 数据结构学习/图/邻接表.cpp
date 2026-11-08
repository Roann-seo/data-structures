#include<iostream>
using namespace std;
//图的邻接表储存
#define MVNum 100
typedef char VerTexType;
typedef int OtherInfo;
typedef struct ArcNode{
    int adjvex;//临接点
    OtherInfo info;
    struct ArcNode*nextarc;
}ArcNode;//边节点
typedef struct VNode{
    VerTexType data;
    ArcNode* firstarc;
}VNode,AdjList[MVNum];//顶点表结点
//别名：将结构体起别名为VNode,同时定义AdjList=VNode[MVNum]
//存放最多MVNum个顶点的表数组
typedef struct{
    AdjList vertices;
    int vexnum,arcnum;//当前定点数和边数
}AMGraph;
//用邻接表方式创建无向图
int LocateVex(AMGraph &G,VerTexType v){
    for(int i=0;i<G.vexnum;i++){
        if(v==G.vertices[i].data){
            return i;
        }
    }
    return -1;
}
int CreateUDG(AMGraph &G){
    cin>>G.vexnum>>G.arcnum;
    for(int i=0;i<G.vexnum;i++){
        cin>>G.vertices[i].data;
        G.vertices[i].firstarc=NULL;
    }
    VerTexType v1,v2;
    OtherInfo w;
    int i,j;
    for(int k=0;k<G.arcnum;k++){
        cin>>v1>>v2>>w;
        i=LocateVex(G,v1);
        j=LocateVex(G,v2);
        ArcNode*p1=new ArcNode;
        p1->adjvex=j;
        p1->info=w;
        p1->nextarc=G.vertices[i].firstarc;
        G.vertices[i].firstarc=p1;
        ArcNode*p2=new ArcNode;
        p2->adjvex=i;
        p2->info=w;
        p2->nextarc=G.vertices[j].firstarc;
        G.vertices[j].firstarc=p2;
    }
    return 1;
}
//优点：空间效率高，易找到顶点的邻接点
//缺点：不易找到两点之间是否有边
//邻接表的空间复杂度为O(n+e)。
//时间复杂度为O(n+e)。
int visited[MVNum];
void DFS(AMGraph G,int v){
    cout<<v;
    visited[v]=1;     
    ArcNode*p=G.vertices[v].firstarc;
    int w;
    while(p!=NULL){
        w=p->adjvex;
        if(visited[w]==0){
            DFS(G,w);
        }
        p=p->nextarc;
    }
}
void Traverse(AMGraph G){
    for(int i=0;i<G.vexnum;i++){
        visited[i]=0;
    }
    for(int i=0;i<G.vexnum;i++){
        if(visited[i]==0){
            DFS(G,i);
        }
    }
}
#define MAXSIZE 100
typedef struct{
    VerTexType data[MAXSIZE];
    int front;
    int rear;
}Queue;
void initQueue(Queue*q){
    q->front=q->rear=0;
}
bool isfull(Queue*Q){
    if((Q->rear+1)%MAXSIZE==Q->front){
        return 1;
    }
    return 0;
}
bool isempty(Queue*Q){
    if(Q->front==Q->rear){
        return 1;
    }
    return 0;
}
void EnQueue(Queue*Q,int t){
    if(isfull(Q)){
        cout<<"满了";
    }
    Q->data[Q->rear]=t;
    Q->rear=(Q->rear+1)%MAXSIZE;
}
void DeQueue(Queue*Q,int &t){
    if(isempty(Q)){
        cout<<"空的";
    }
    t= Q->data[Q->front];
    Q->front=(Q->front+1)%MAXSIZE;
}
void BFS(AMGraph &G,int v){
    cout<<v;
    visited[v]=1;
    Queue*q;
    initQueue(q);
    EnQueue(q,v);
    while(isempty(q)){
        int u;
        DeQueue(q,u);
        ArcNode*p=G.vertices[u].firstarc;
        while(p!=NULL){
            int w=p->adjvex;
            if(!visited[w]){
                cout<<G.vertices[w].data;
                visited[w]=1;
                EnQueue(q,w);
            }
            p=p->nextarc;
        }
    }
}