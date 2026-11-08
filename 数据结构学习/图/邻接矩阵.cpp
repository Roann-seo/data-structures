#include<iostream>
using namespace std;
//图的邻接矩阵储存
#define MaxInt 32767
#define MVNum 100
typedef char VerTexType;
typedef int ArcType;
typedef struct{
    VerTexType vexs[MVNum];//顶点集
    ArcType arcs[MVNum][MVNum];//边集
    int vexnum,arcnum;//顶点数，边数
}AMGraph;
//采用邻接矩阵表示法创建无向网
int CreateUDN(AMGraph &G){
    cin>>G.vexnum>>G.arcnum;
    for(int i=0;i<G.vexnum;i++){
        cin>>G.vexs[i];
    }
    for(int i=0;i<G.vexnum;i++){
        for(int j=0;j<G.vexnum;j++){
            G.arcs[i][j]=MaxInt;
        }
    }
    int i,j;
    for(int k=0;k<G.arcnum;k++){
        VerTexType v1,v2;
        ArcType w;
        cin>>v1>>v2>>w;
        i=LocateVex(G,v1);
        j=LocateVex(G,v2);
        G.arcs[i][j]=w;
        G.arcs[j][i]=G.arcs[i][j];
    }
    return 1;
}
int LocateVex(AMGraph &G,VerTexType v){
    for(int i=0;i<G.vexnum;i++){
        if(v==G.vexs[i]){
            return i;
        }
    }
    return -1;
}
//邻接矩阵表示法优点：
//1.便于观察两个顶点之间是否有边
//2.便于看顶点的度，无向图：第i行元素之和就是顶点vi的度。有向图：第i行元素之和是第vi顶点的出度，列是入度
// 缺点：
// 1.不利于增加或删除节点
// 2.不利于找出边的数目
// 3.空间复杂度高
//邻接矩阵的空间复杂度为O(n**2)
//深度优先遍历邻接矩阵
//邻接矩阵来表示图,时间复杂度为O(n**2)。
int visited[MVNum];
void DFS(AMGraph G,int v){
    cout<<v;
    visited[v]=1;
    for(int w=0;w<G.vexnum;w++){
        if(G.arcs[v][w]!=0&&visited[w]!=1){
            DFS(G,w);
        }
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