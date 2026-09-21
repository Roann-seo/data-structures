// n个人（0,1,2,3,4...n-1），围成一圈，从编号为k的人开始报数，
// 报数报到m的人出队（报数是1,2,...m这样报的）。
// 下次从出队的人之后开始重新报数，循环往复，
// 当队伍中只剩最后一个人的时候，那个人就是大王。
// 现在，给定n，k，m，请你求出大王的编号。
#include <iostream>
using namespace std;

int main() {
    int n,m,k;
    cin>>n>>k>>m;
    int a[105];
    for(int i=0;i<n;i++){
        a[i]=1;
    }
    int live=n;
    int cur=k;
    int cnt=0;
    while(live>1){
        if(a[cur]==1){
            cnt++;
            if(cnt==m){
                live--;
                a[cur]=0;
                cnt=0;
            }
        }
        cur=(cur+1)%n;
    }
    int win=0;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            win=i;
        }
    }
    cout<<win;
    return 0;
}