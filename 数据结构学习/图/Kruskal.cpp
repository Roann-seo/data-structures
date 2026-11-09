#include<iostream>
#include<algorithm>
using namespace std;
const int INX=0x3f3f3f3f;
const int MAXV=100;
typedef struct{
    int vexnum;
    int arcnum;
    int vexs[MAXV];
    int arcs[MAXV][MAXV];
}AMGraph;
typedef struct{
    int head,tail;
    int weight;
}Edge;
bool cmp(Edge edge1,Edge edge2){
    return edge1.weight<edge2.weight;
}
int locatevex(AMGraph G,int u){
    for(int i=0;i<G.vexnum;i++){
        if(G.vexs[i]==u){
            return i;
        }
    }
    return -1;
}
void MiniSpanTree_Kruskal(AMGraph G, Edge Edge[]){
    int vexset[MAXV];
    sort(Edge);
    for(int i=0;i<G.vexnum;i++){
        vexset[i]=i;
    }
    for(int j=0;j<G.vexnum;j++){
        int v1=locatevex(G,Edge[j].head);
        int v2=locatevex(G,Edge[j].tail);
        int vs1=vexset[v1];
        int vs2=vexset[v2];
        if(vs1!=vs2){
            cout<<Edge[j].head<<" "<<Edge[j].tail<<" "<<Edge[j].weight;
            for(int i=0;i<G.vexnum;i++){
                if(vexset[i]==vs2){
                    vexset[i]=vs1;
                }
            }
        }
    }
}
int main()
{
    AMGraph G;
    G.vexnum = 4;
    G.arcnum = 5;
    G.vexs[0]=0;G.vexs[1]=1;G.vexs[2]=2;G.vexs[3]=3;
    Edge e[5] = {
        {0,1,1},
        {0,2,5},
        {1,2,2},
        {1,3,4},
        {2,3,1}
    };
    sort(e, e+5, cmp);
    cout << "Kruskal最小生成树边：\n";
    MiniSpanTree_Kruskal(G,e);
    return 0;
}