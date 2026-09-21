// **神秘石像的镜像序列：**
// 输入若干数字，**以 0 作为结束标记**，0 不算入序列。
// 把读到的数字**倒序输出**。
// 示例输入：`1098373073 1662319662 185545370 0`
// 读到的有效数字：`[1098373073, 1662319662, 185545370]`
// 倒序输出：`185545370 1662319662 1098373073`
#include <iostream>
using namespace std;

int main() {
    
    long long arr[105];
    int count=0;
    long long x;
    cin>>x;//读入第一个数
    while(x!=0){
        arr[count]=x;
        count++;
        cin>>x;
    }//
    for(int i=count-1;i>=0;i--){
        cout<<arr[i]<<" ";//倒序输出
    }
    // for(int i=0;i<count/2;i++){
    //     long long temp=arr[i];
    //     arr[i]=arr[count-i];
    //     arr[count-i]=temp;
    // }
    // for(int i=0;i<count/2;i++){
    //         cout<<arr[i]<<" ";
    // }
    return 0;
}