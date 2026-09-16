// # 题目：求整数二进制里 1 的个数

// 示例：`9 → 二进制1001 → 有2个1`
#include<stdio.h>
int countone(int n){
    int count=0;
    while(n!=0){
        n=n&(n-1);
        //每执行一次，干掉**恰好 1 个 1**。所以适合统计二进制里 1 的个数
        //9->1001
        //8->1000
        //----&----
        //0001
        count++;
    }
    return count;
}
int main(){
    int x;
    scanf("%d",&x);
    printf("二进制里面的1有%d位",countone(x));
    return 0;
}