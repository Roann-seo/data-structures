// 后缀表达式求值：建立一个操作数栈S。然后从左到右读表达式，如果读到操作数就将它压入栈S中，
// 如果读到n元运算符(即需要参数个数为n的运算符)则取出由栈顶向下的n项操作数进行运算，
// 再将运算的结果代替原栈顶的n项压入栈中。重复上面过程，如果后缀表达式读完且栈中只剩一个操作数，
// 则该数就是运算结果；如果后缀表达式读完但是栈中操作数多于一个，则后缀表达式错误；
// 如果栈中操作数只剩一个，但是后缀表达式还未读完且当前运算符为双元操作符，则后缀表达式同样错误。
// // 输入格式:
// // 在一行中输入一个以#号结束的非空后缀式，#不属于表达式的一部分，操作数和运算符都以空格分隔
// ，运算数为绝对值不超过100的整数，运算符仅有+、-、*、/ 四种。
// // 输出格式:
// // 输出后缀式计算结果，所有的计算都只取结果的整数部分。
// 题目保证计算的中间和最后结果的绝对值都不超过109。如果执行除法时出现分母为零的非法操作，
// 则在一行中输出：Error: X/0，X是当时的分子。如果后缀表达式中运算符多了或者少了，
// 则在一行中输出：Expression Error: X，X是当时栈顶元素。
// 输入样例1：5 -2 + 3 * #  输出：9
// 输入样例2：5 -2 2 + / #   输出：Error: 5/0
// 输入样例3：5 -1 3 + / - * #   输出Expression Error: 2
#include<iostream>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 100
using namespace std;
typedef struct{
    int data[MAXSIZE];
    int top;
}Stack;
void initstack(Stack *s){
    s->top=-1;
}
int push(Stack*s,int e){
    if(s->top>=MAXSIZE){
        return 0;
    }
    s->data[++s->top]=e;
    return 1;
}
int pop(Stack*s,int *e){
    if(s->top==-1){
        return 0;
    }
    *e=s->data[s->top--];
    return 1;
}
int gettop(Stack*s){
    return s->data[s->top];
}
int main(){
    Stack*s=new Stack;
    initstack(s);
    char token[20];
    bool err=false;
    while(scanf("%s",token)==1&&err==false){
        if(strcmp(token,"#")==0){
            break;
        }if(strlen(token)==1&&(token[0]=='+'||token[0]=='-'||token[0]=='*'||token[0]=='/')){
            int a,b,res;
            if(!pop(s,&b)||!pop(s,&a)){
                int top1=gettop(s);
                cout<<"Expression Error:"<<top1<<endl;
                err=true;
            }else{
                char op=token[0];
                if(op=='+'){
                    res=a+b;
                }else if(op=='-'){
                    res=a-b;
                }else if(op=='*'){
                    res=a*b;
                }else{
                    if(b==0){
                        cout<<"Error: "<<b<<"/0"<<endl;
                        err=true;
                    }else{
                        res=a/b;
                    }
                }
                push(s,res);
            }
        }else{
            int num=atoi(token);//将token（char)类型转换成int类型
            push(s,num);
        }
    }
    int ans;
    if(s->top==0){
        ans=gettop(s);
        cout<<ans<<endl;
    }else{
        ans=gettop(s);
        cout<<"Expression Error:"<<ans<<endl;
    }
    return 0;
}