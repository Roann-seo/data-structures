// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

// 有效字符串需满足：

// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 每个右括号都有一个对应的相同类型的左括号。
#include<stdio.h>
#include<stdbool.h>
bool isValid(char* s) {
    char stack[10000];
    int top=0;
    while(*s!='\0'){
        if(*s=='('||*s=='['||*s=='{'){
            stack[top++]=*s;
            //入栈
        }else{
            if(top==0){
                return false;
            }
            char left=stack[--top];
            //出栈，先将top--再使用
            if((*s==')'&&left!='(')||
            (*s=='}'&&left!='{')||
            (*s==']'&&left!='[')){
                return false;
            }
        }
        s++;
    }
    return top==0;
}