// 设某银行有A、B两个业务窗口，且处理业务的速度不一样，其中A窗口处理速度是B窗口的2倍 —— 即当A窗口每处理完2个顾客时，B窗口处理完1个顾客。给定到达银行的顾客序列，请按业务完成的顺序输出顾客序列。假定不考虑顾客先后到达的时间间隔，并且当不同窗口同时处理完2个顾客时，A窗口顾客优先输出。
// 输入格式:
// 输入为一行正整数，其中第1个数字N(≤1000)为顾客总数，后面跟着N位顾客的编号。编号为奇数的顾客需要到A窗口办理业务，为偶数的顾客则去B窗口。数字间以空格分隔。
// 如：8 2 1 3 9 4 11 13 15
// 输出格式:
// 按业务处理完成的顺序输出顾客的编号。数字间以空格分隔，但最后一个编号后不能有多余的空格。
// 如：1 3 2 9 11 4 13 15
#include<iostream>
#define MAXSIZE 1000
using namespace std;
typedef struct {
    int data[MAXSIZE];
    int length;
}Sqlist;
int main(){
    Sqlist*s1=new Sqlist;
    Sqlist*s2=new Sqlist;
    int p=0;
    int q=0;
    int n;
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x%2==0){
            s1->data[s1->length]=x;
            s1->length++;//放偶数p
        }else{
            s2->data[s2->length]=x;
            s2->length++;//放奇数q
        }
    }
    bool first=true;
    while(p<s1->length||q<s2->length){
        int take=0;
        while(q<s2->length&&take<2){
            if(!first){
                cout<<" ";
            }
            cout<<s2->data[q++];
            first=false;
            take++;
        }if(p<s1->length){
            if(!first){
                cout<<" ";
            }
            cout<<s1->data[p++];
            first=false;
        }
    }
    
    return 0;
}