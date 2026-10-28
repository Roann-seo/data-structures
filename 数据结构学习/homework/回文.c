#include<stdio.h>
#include<string.h>
#define MAXSIZE 100
typedef struct{
    char data[MAXSIZE];
    int top;
}Stack;
int push(Stack*s,char ch){
    if(s->top==MAXSIZE-1){
        return 0;
    }
    s->top++;
    s->data[s->top]=ch;
    return 1;
}
int pop(Stack*s,char *ch){
    if(s->top==-1){
        return 0;
    }
    *ch=s->data[s->top];
    s->top--;
    return 1;
}
int isreverse_same(char str[],Stack*s){
    s->top=-1;
    for(int i=0;i<strlen(str);i++){
        push(s,str[i]);
    }
    char ch;
    int j=0;
    while(s->top!=-1){
        pop(s,&ch);
        if(ch!=str[j]){
            return 0;
        }
        j++;
    }
    return 1;
}
int main()
{
    Stack st;
    char s1[] = "abba";
    char s2[] = "good";
    if(isreverse_same(s1,&st))
        printf("%s 是回文\n",s1);
    else
        printf("%s 不是回文\n",s1);
    if(isreverse_same(s2,&st))
        printf("%s 是回文\n",s2);
    else
        printf("%s 不是回文\n",s2);
    return 0;
}