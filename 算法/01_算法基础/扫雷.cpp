#include <iostream>
using namespace std;
char a[1005][1005];
int main() {
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int dx[]={-1,-1,-1,0,0,1,1,1};
    int dy[]={-1,0,1,-1,1,-1,0,1};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='*'){
                cout<<'*';
            }else{
                int cnt=0;
                for(int k=0;k<8;k++){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(nx>=0&&nx<=n&&ny>=0&&ny<=m){
                        if(a[nx][ny]=='*'){
                            cnt++; 
                        }
                    }
                }
                cout<<cnt;
            }
        }
        cout<<endl;
    }
    return 0;
    
}