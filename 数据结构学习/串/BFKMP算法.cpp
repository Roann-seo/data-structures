#include<iostream>
#include<string>
using namespace std;
#define MAXSIZE 225
typedef struct {
    char ch[MAXSIZE];
    int length;
}SString;
int BF(SString S,SString T,int pos){
    //S是主串T是子串
    int i=pos;
    int j=1;
    while(i<=S.length&&j<=T.length){
        if(S.ch[i]==T.ch[j]){
            i++;
            j++;
        }
        else{
            i=i-j+2;//不能写成i=i-1，因为有时候会前三个对上
            j=1;
        }
    }
    if(j>T.length){
        return i-T.length;//返回在主串的位置 
    }else{
        return 0;
    }
}//时间复杂度(O(nxm))
//KMP算法
void next(SString T,int next[]){
    //j一直往后移，只有k动
    int j=1;//J是后缀的末尾指针
    int k=0;//k是前缀的末尾指针
    next[1]=0;
    while(j<T.length){
        if(k==0||T.ch[j]==T.ch[k]){
            j++;
            k++;
            next[j]=k;//next数组的值为前缀的末尾指针，即为最大相同前后缀
        }else{
            k=next[k];//将k回退到前后缀相同的最小长度
        }
    }
}
void nextval(SString T,int next[],int nextval[]){
    int j=1;
    nextval[1]=0;
    while(j<T.length){
        j++;
        if(T.ch[j]==T.ch[next[j]]){
            nextval[j]=nextval[next[j]];
        }else{
            nextval[j]=next[j];
        }
    }
}
int index_KMP(SString S,SString T,int pos){
    int i=pos;
    int j=1;
    int nextArr[MAXSIZE];
    next(T,nextArr);
    while(i<=S.length&&j<=T.length){
        if(S.ch[i]==T.ch[j]||j==0){
            i++;
            j++;
        }else{
            j=nextArr[j];
        }
    }
    if(j>T.length){
        return i-T.length;
    }else{
        return 0;
    }
}
//nextval 就是用来干掉这种**相同字符的重复无效比对**。
int index_KMP_nextval(SString S,SString T,int pos){
    int i=pos;
    int j=1;
    int nextArr[MAXSIZE];
    int nextvalArr[MAXSIZE];
    next(T,nextArr);
    nextval(T,nextArr,nextvalArr);
    while(j<=T.length&&i<=S.length){
        if(T.ch[j]==S.ch[i]||j==0){
            i++;
            j++;
        }else{
            j=nextvalArr[j];
        }
    }
    if(j>T.length){
        return i-T.length;
    }else{
        return 0;
    }
}
void StrAssign(SString &str, const char *s){
    str.length = 0;
    int i=1;
    while(s[str.length]!='\0'){
        str.ch[i++] = s[str.length];
        str.length++;
    }
}
int main(){
    SString S,T;
    StrAssign(S,"ababcababac");
    StrAssign(T,"ababac");
    cout<<"BF结果:"<<BF(S,T,1)<<endl;
    cout<<"KMP(next)结果："<<index_KMP(S,T,1)<<endl;
    cout<<"KMP(nextval)结果："<<index_KMP_nextval(S,T,1)<<endl;
    return 0;
}


