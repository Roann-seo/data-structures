// 极小连通子图：该子图是G 的连通子图，在该子图中删除任何一条边，子图不再连通。
// 生成树：包含图G所有顶点的极小连通子图（n-1条边）。
//Prim
#include<iostream>
#include<cstring>
using namespace std;
const int MAXV=100;
const int INF=0x3f3f3f3f;
typedef struct{
    int vexnum,arcnum;
    int vexs[MAXV];
    int arcs[MAXV][MAXV];
}AMGraph;
typedef struct{
    int adjvex;
    int lowcost;
}ClosedEdge;
int locatevex(AMGraph G,int u){
    for(int i=0;i<G.vexnum;i++){
        if(G.vexs[i]==u){
            return i;
        }
    }
    return -1;
}
int min(ClosedEdge closedge[],int n){
    int k=-1;
    int minest=INF;
    for(int i=0;i<n;i++){
        if(closedge[i].lowcost!=0&&closedge[i].lowcost<minest){
            minest=closedge[i].lowcost;
            k=i;
        }
    }
    return k;
}
void MiniSpanTree_Prim(AMGraph G,int u){
    int k=locatevex(G,u);
    ClosedEdge closedge[MAXV];
    //初始化这个数组
    for(int i=0;i<G.vexnum;i++){
        closedge[i].adjvex=k;
        closedge[i].lowcost=G.arcs[k][i];
    }
    closedge[k].lowcost=0;
    for(int i=1;i<G.vexnum;i++){
        k=min(closedge,G.vexnum);//即将加入集合U的下标
        int u0=closedge[k].adjvex;//在U中距离最近的邻接点下标
        int v0=G.vexs[k];//不在U中的顶点值
    }
    closedge[k].lowcost=0;
    for(int j=0;j<G.vexnum;j++){
        if(closedge[j].lowcost!=0&&closedge[j].lowcost>G.arcs[k][j]){
            closedge[j].adjvex=k;
            closedge[j].lowcost=G.arcs[k][j];
        }
    }
}
int main()
{
    AMGraph G;
    G.vexnum = 4;
    G.arcnum = 5;
    // 顶点编号：0,1,2,3 对应A,B,C,D
    G.vexs[0] = 0;
    G.vexs[1] = 1;
    G.vexs[2] = 2;
    G.vexs[3] = 3;
    // 矩阵初始化无穷
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            G.arcs[i][j] = INF;
    for(int i=0;i<4;i++) G.arcs[i][i]=0;

    // 边：0-1(1), 0-2(5), 1-2(2),1-3(4),2-3(1)
    G.arcs[0][1] = G.arcs[1][0] = 1;
    G.arcs[0][2] = G.arcs[2][0] = 5;
    G.arcs[1][2] = G.arcs[2][1] = 2;
    G.arcs[1][3] = G.arcs[3][1] = 4;
    G.arcs[2][3] = G.arcs[3][2] = 1;

    cout << "最小生成树边：" << endl;
    MiniSpanTree_Prim(G, 0);
    return 0;
}