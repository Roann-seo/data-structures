// 用**纯递归**写二维斐波那契，直接超时了。

// > 
// > 题目限制：`n,m ≤ 1000`
// > 递归会大量重复计算，比如`fab(13,44)`会反复算同一个子问题，指数级爆炸，1 秒根本跑不完。
// > 而且递归层数太深还容易栈溢出。
//递归方法，可以每次记录已经计算过的结果，避免重复计算。
// #include <iostream>
// using namespace std;
// int fab(int n,int m){
//     if(n==1&&m==1){
//         return 1;
//     }else if(n>=2&&m==1){
//         return fab(n-1,m);
//     }else if(m>=2&&n==1){
//         return fab(n,m-1);
//     }else{
//         return fab(n-1,m)+fab(n,m-1);
//     }
// }
// int main() {
//     int n,m;
//     cin>>n>>m;
//     cout<<(fab(n,m))<<endl;
//     return 0;
// }

//方法二：动态规划利用二维数组
#include <iostream>
using namespace std;
const int MAXN=1000;
const long long mod=1e9+7;
long long dp[MAXN][MAXN];
int main() {
    int n,m;
    cin>>n>>m;
    dp[1][1]=1;
    for(int i=2;i<=n;i++){
        dp[i][1]=dp[i-1][1]%mod;
    }
    for(int j=2;j<=m;j++){
        dp[1][j]=dp[1][j-1]%mod;
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
        }
    }
    cout<<dp[n][m]<<endl;
}