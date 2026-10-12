// 已知长度为n的线性表A采用顺序存储结构,
// 请写一时间复杂度为O（n）、空间复杂度为O（1）的算法,
// 该算法删除线性表中所有值为item的数据元素。
#include<stdio.h>
typedef int Elemtype;
typedef struct{
    Elemtype*data;
    int length;
}Sqlist;
Sqlist*deletelist(Sqlist*a,Elemtype item){
    int k=0;
    for(int i=0;i<a->length;i++){
        if(a->data[i]!=item){
            a->data[k]=a->data[i];
            k++;
        }
    }
    a->length=k;
    return a;
}