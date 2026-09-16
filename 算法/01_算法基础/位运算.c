//判断奇偶数
// #include<stdio.h>
// int main(){
//     int n;
//     scanf("%d",&n);
//     if(n&1){
//         printf("奇数\n");
//     }else{
//         printf("偶数\n");
//     }
//     return 0;
// }



//获取第k位二进制是1还是0
// #include<stdio.h>
// int main(){
//     int n;//获取这个数
//     scanf("%d",&n);
//     int k;//找到数的第几位
//     scanf("%d",&k);
//     printf("%d\n",(n>>k)&1);
//     //往右移动k位
//     return 0;
// }


//异或交换两个整数，不用临时变量
// #include<stdio.h>
// int main(){
//     int a,b;
//     scanf("%d %d",&a,&b);
//     a=a^b;
//     b=a^b;
//     a=a^b;
//     printf("%d %d\n",a,b);
//     return 0;
// }


// 不用 if 判断，求整数绝对值
#include<stdio.h>
int abt(int x){
    int mask=x>>31;
    return (x^mask)-mask;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("绝对值:%d\n",abt(n));
    return 0;
}