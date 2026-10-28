#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int Elemtype;
typedef struct{
    int coef;
    int exp;
}PolyTerm;
typedef struct {
    PolyTerm data[MAXSIZE];
    int length;
}Sqlist;
void initlist(Sqlist*L){
    L->length=0;
}
void InsertSqPoly(Sqlist *L, int c, int e){
    //这是相同系数的
    for(int i=0;i<L->length;i++){
        if(L->data[i].exp==e){
            L->data[i].coef+=c;
            if(L->data[i].coef==0){
                for(int j=i;j<L->length-1;j++){
                    L->data[j]=L->data[j+1];
                }
                L->length--;
            }
            //找到系数为0的，直接删除
            return ;
        }
    }
    //系数不同，寻找插入位置,降序
    int pos=0;
    while(pos<L->length&&L->data[pos].exp>e){
        pos++;
    }
    for(int j=L->length;j>pos;j--){
        L->data[j]=L->data[j-1];              
    }
    L->data[pos].coef=c;
    L->data[pos].exp=e;
    L->length++;
}
void CreateSqPoly(Sqlist *L){
    initlist(L);
    int c,e;
    printf("请输入多项式的系数 指数,输入0 0结束\n");
    while(scanf("%d%d",&c,&e)==2&&(c!=0||e!=0)){
        InsertSqPoly(L,c,e);
    }
}
void AddSqPoly(Sqlist*La,Sqlist*Lb,Sqlist*Lc){
    initlist(Lc);
    for(int i=0;i<La->length;i++){
        InsertSqPoly(Lc,La->data[i].coef,La->data[i].exp);
    }
    for(int i=0;i<Lb->length;i++){
        InsertSqPoly(Lc,Lb->data[i].coef,Lb->data[i].exp);
    }
}
void PrintSqPoly(Sqlist*L){
    if(L->length==0){
        printf("0");
        return ;
    }
    for(int i=0;i<L->length;i++){
        if(L->data[i].coef>0&&i!=0){//i!=0排除第一项
            printf("+");
        }
        printf("%d",L->data[i].coef);
        if(L->data[i].exp>0){
            printf("x^%d",L->data[i].exp);
        }
    }
}
int main(){
    Sqlist ha,hb,hc;
    printf("=====顺序表多项式ha=====\n");
    CreateSqPoly(&ha);
    printf("=====顺序表多项式hb=====\n");
    CreateSqPoly(&hb);
    AddSqPoly(&ha,&hb,&hc);
    printf("\nha = "); PrintSqPoly(&ha);
    printf("\nhb = "); PrintSqPoly(&hb);
    printf("\nhc = ha+hb = "); PrintSqPoly(&hc);
    printf("\n");
    return 0;
}