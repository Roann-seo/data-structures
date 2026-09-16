//&运算符 1&1=1 0&0=0 1&0=0 0&1=0 用来消除不同的数字
//^       1^1=0 0^0=0 1^0=1 0^1=1 用来消除相同元素
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin>>a>>b;
    int x;
    x=a^b;
    //1&1=1 0&0=0
    //1^1=0 0^0=0相同为0不同为1
    //统计二进制里面1的个数
    // int count=0;
    // while(x!=0){
    //     x=x&(x-1);
    //     count++;
    // }
    // cout<<count;
    int cnt=0;
    while(x>0){
        if(x&1){
            cnt++;
        }
        x=x>>1;
    }
    cout<<cnt;
}
// 64 位输出请用 printf("%lld")
// 1. BGN80（统计 1 的个数）：`x = x & (x-1)`，**抹掉最右边的 1** → 用 &
// 2. BGN81（求二进制不同位数）：`x = a ^ b`，**标记所有不一样的 bit 为 1** → 用 ^
// 3. BGN82（被打乱的异或和）：利用 `x ^ x =0` 抵消 → 用 ^