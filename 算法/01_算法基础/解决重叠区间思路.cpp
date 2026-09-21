// 思路：

// 1. 开一个数组 `tree[10001]`（L 最大是 10000），初始全部设为 1，代表有树。
// 2. 遍历每一个施工区间 `[l, r]`：把区间内所有点标记成 `0`（树被挖掉）。

// > 
// > 👉 重点：**不管重叠多少次，只要标记一次 0 就够了，自动解决重叠！不用手动找重叠！**

// 3. 最后统计数组里面等于 1 的个数，就是剩下的树。
#include <iostream>
using namespace std;

int main() {
    int L,M;
    cin>>L>>M;
    int tree[10005]={0};
    for(int i=0;i<=L;i++){
        tree[i]=1;
    }
    
    for(int i=0;i<M;i++){
        int l,r;
        cin>>l>>r;
        for(int j=l;j<=r;j++){
            tree[j]=0;
        }
    }
    int ans=0;
    for(int i=0;i<=L;i++){
        if(tree[i]==1){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}