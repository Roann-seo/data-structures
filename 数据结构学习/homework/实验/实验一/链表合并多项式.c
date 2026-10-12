#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int Elemtype;
typedef struct{
    int exp;
    int coef;
}PolyTerm;
typedef struct node{
    PolyTerm data;
    struct node*next;
}Node;
Node* initlist(){
    Node*L=(Node*)malloc(sizeof(Node));
    L->next=NULL;
    return L;
}
void InsertPolyList(Node* L, int c, int e){
    //相同系数
    Node*p=L->next;
    Node*q=L;
    while(p!=NULL){
        if(p->data.exp==e){
            p->data.coef+=c;
            if(p->data.coef==0){
                q->next=p->next;
                free(p);
            }
            return ;
        } 
        q=p;       
        p=p->next;
    }
    //系数不同(降序)
    p=L->next;
    q=L;
    Node*newnode=(Node*)malloc(sizeof(Node));
    newnode->data.coef=c;
    newnode->data.exp=e;
    newnode->next=NULL;
    while(p!=NULL&&p->data.exp>e){
        q=p;
        p=p->next;
    }
    newnode->next=p;
    q->next=newnode;
}
Node* CreatePolyList(){
    Node*L=initlist();
    int c,e;
    printf("请输入多项式的系数,指数:(输入0 0结束)\n");
    while(scanf("%d%d",&c,&e)==2&&(c!=0||e!=0)){
        InsertPolyList(L,c,e);
    }
    return L;
}
Node* AddPolyList(Node*L1,Node*L2){
    //多项式的相加，把它当作先把L1中所有元素扔进L3，在运用InsertPolyList函数，
    //将L2里面的元素插入到L3里面
    Node*L3=initlist();
    Node*p=L1->next;
    while(p!=NULL){
        InsertPolyList(L3,p->data.coef,p->data.exp);
        p=p->next;
    }
    p=L2->next;
    while(p!=NULL){
        InsertPolyList(L3,p->data.coef,p->data.exp);
        p=p->next;
    }
    return L3;
}
void PrintPolyList(Node*L){
    Node*p=L->next;
    if(L==NULL){
        printf("空\n");
    }
    while(p!=NULL){
        if(p->data.coef>0&&p!=L->next){
            printf("+");
        }
        printf("%d",p->data.coef);
        if(p->data.exp>0){
            printf("x^%d",p->data.exp);
        }
        p=p->next;
    }
}
int main()
{
    Node* ha;
    Node* hb;
    Node* hc;
    printf("=====单链表多项式ha=====\n");
    ha=CreatePolyList();
    printf("=====单链表多项式hb=====\n");
    hb=CreatePolyList();
    hc=AddPolyList(ha, hb);

    printf("\nha = "); PrintPolyList(ha);
    printf("\nhb = "); PrintPolyList(hb);
    printf("\nhc = ha+hb = "); PrintPolyList(hc);
    printf("\n");

    
    return 0;
}
