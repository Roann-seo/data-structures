// 1~N 里面，每个数字出现 2 次，只有 1 个数字只出现 1 次，找出这个唯一的数
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    int N=5;
    int arr[100];
    for(int i=0;i<N-1;i++){
        arr[i]=i+1;
    }
    srand((unsigned)time(NULL));
    int randnum=rand()%N+1;
    arr[N-1]=randnum;
    //随机交换
    int idx=rand()%N;
    int temp=arr[idx];
    arr[idx]=arr[N-1];
    arr[N-1]=temp;
    int x=0;
    for(int i=0;i<N;i++){
        x=i^x;//这个数组里面有从0到N-1的所有数
    }
    for(int i=0;i<N;i++){
        x=x^arr[i];
    }
    printf("%d ",x);
    return 0;
}