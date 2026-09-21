//BGN82 被打乱的异或和
// 原来的数组：\(b_1,b_2,\dots,b_{n-1}\)，原数组异或和 \(x = b_1 \oplus b_2 \oplus \dots \oplus b_{n-1}\)
// 新数组 a 是把 x 插入到原数组里面得到的，所以新数组长度为 n。
// 也就是：\(a = [b_1,b_2,\dots,b_{n-1},\ x]\)
#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    int arr[128];
    for(int i=0;i<t;i++){
        int n;
        int x=0;
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        for(int j=0;j<n-1;j++){
            x^=arr[j];
            //0^x=x
            //0&x=0
        }
        cout<<x<<endl;
    }
    
}