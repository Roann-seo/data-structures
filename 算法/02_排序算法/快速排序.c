#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int*a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void partition(int arr[], int L, int R, int res[2]){
    int less=L-1;
    int more=R;
    int i=L;
    while(i<more){
        if(arr[i]<arr[R]){
            less++;
            swap(&arr[i],&arr[less]);
            i++;
        }
        else if(arr[i]>arr[R]){
            more--;
            swap(&arr[i],&arr[more]);
        }else{
            i++;
        }
    }
    swap(&arr[R],&arr[more]);
    //循环结束了，只有arr[R]作为基准还在最后一个位置，此时arr[more]在大于基准的第一个位置
    //正好将两个交换
    res[0]=less+1;
    res[1]=more;
}
void quicksort3(int arr[],int L,int R){
    if(L>R){
        return;
    }
    srand((unsigned)time(NULL));
    int randidx=L+rand()%(R-L+1);
    swap(&arr[randidx],&arr[R]);
    int eq[2];
    partition(arr,L,R,eq);
    quicksort3(arr,L,eq[0]-1);
    quicksort3(arr,eq[1]+1,R);
}
int main(void)
{
    int nums[] = {8, 3, 6, 2, 9, 1, 5, 7};
    int n = sizeof(nums)/sizeof(nums[0]);
    quicksort3(nums,0,n-1);
    for(int i=0;i<n;i++) printf("%d ",nums[i]);
    return 0;
}