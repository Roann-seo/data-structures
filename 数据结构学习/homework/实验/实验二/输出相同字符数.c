// 输入格式：
// 输入分 110 行，每行对应 110 位手机号码的一位数字，给出由 m 组成的字符串，以回车结束。
// 每个 m 代表鱼漂上的一目，一行中有多少 m 就表示这一位数字是多少，空行代表 0。题目保证每行都不超过 9 个 m。

// 输出格式：
// 在一行中输出钓鱼佬的手机号的前2位。
// m
// mm
// mmmmmmmm
// mmm
// m
// mm
// m
// mmmmmmmm
//
// mmmmmmmm
// mm
//12831218082
#include<stdio.h>
int main(){
    for(int i=0;i<11;i++){
        char buf[10];
        fgets(buf,10,stdin);
        int cnt=0;
        for(int j=0;buf[j]!='\0';j++){
            if(buf[j]=='m'){
                cnt++;
            }
        }
        printf("%d",cnt);
    }
    printf("\n");
    return 0;
}