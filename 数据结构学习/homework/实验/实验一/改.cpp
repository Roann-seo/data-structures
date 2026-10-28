#include<iostream>
#include<cstdlib>
using namespace std;
#define MAXSIZE 100
typedef struct{
    int coef;
    int exp;
}PolyTerm;
typedef struct{
    PolyTerm data[MAXSIZE];
    int length;
}Sqlist;
void initlist(Sqlist*s1){
    s1->length=0;
}
void insertlist(Sqlist*s1,int c,int e){
    //指数相同时
    for(int i=0;i<s1->length;i++){
        if(s1->data[i].exp==e){
            s1->data[i].coef+=c;
            if(s1->data[i].coef==0){
                for(int j=i;j<s1->length-1;j++){
                    s1->data[j]=s1->data[j+1];
                }
                s1->length--;
            }
            return ;//一旦找到指数相同的，就退出循环
        }
    }
    //当指数不相同时(降序)
    int pos=0;
    while(s1->data[pos].exp>e&&pos<s1->length){
        pos++;
    }
    for(int i=s1->length;i>pos;i--){
        s1->data[i]=s1->data[i-1];
    }
    s1->data[pos].coef=c;
    s1->data[pos].exp=e;
    s1->length++;
}
void createlist(Sqlist *s1){
    initlist(s1);
    int c,e;
    cout<<"请输入系数和指数：(输入0 0停止)"<<endl;
    while(cin>>c>>e&&(c!=0||e!=0)){
        insertlist(s1,c,e);
    }
}
void addlist(Sqlist*s1,Sqlist*s2,Sqlist*s3){
    initlist(s3);
    for(int i=0;i<s1->length;i++){
        insertlist(s3,s1->data[i].coef,s1->data[i].exp);
    }
    for(int i=0;i<s2->length;i++){
        insertlist(s3,s2->data[i].coef,s2->data[i].exp);
    }
}
void printlist(Sqlist*s3){
    if(s3==NULL){
        cout<<"NULL";
    }else{
        for(int i=0;i<s3->length;i++){
            if(s3->data[i].coef>0&&i!=0){
                cout<<"+";
            }
            cout<<s3->data[i].coef;
            if(s3->data[i].exp>0){
                cout<<"x^"<<s3->data[i].exp;
            }
        }
    }
}
int main(){
    Sqlist s1;
    createlist(&s1);
    Sqlist s2;
    createlist(&s2);
    Sqlist s3;
    initlist(&s3);
    addlist(&s1,&s2,&s3);
    printlist(&s3);
    return 0;

}