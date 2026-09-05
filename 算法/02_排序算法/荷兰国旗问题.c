// 题目：给定数组、基准值`pivot`，**原地**把数组分成三块：
// 【小于 pivot】｜【等于 pivot】｜【大于 pivot】，不需要整体排序，只分区。
// 力扣 75 颜色分类就是它的特例（只有 0,1,2 三种数）。
#include<stdio.h>
void swap(int*a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
/*
荷兰国旗划分函数
arr：数组
left：当前区间左边界
right：当前区间右边界
pivot：划分基准值
res[0]返回等于区左边界，res[1]返回等于区右边界
*/
void dutchFlag(int arr[], int left, int right, int pivot, int res[2]){
    int less=left-1;
    int greater=right+1;
    int i=left;
    while(i<greater){
        //不能写i<=right,因为greater往后都是大于pivot的
        if(arr[i]<pivot){
            swap(&arr[i],&arr[less+1]);
            //必须交换，因为要把小于pivot的元素放在小于的边界那里
            i++;
            less++;
        }else if(arr[i]>pivot){
            swap(&arr[i],&arr[greater-1]);
            greater--;
//             **`arr[i]>pivot`交换之后，`i不要++`**
// 因为交换过来的arr[greater-1]还没有判断
        }else{
            i++;
            //如果等于的话直接++
        }
    }
    res[0]=less+1;
    res[1]=greater-1;
}
int main(void)
{
    int arr[] = {2,0,2,1,1,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int eqBound[2];
    int pivot = 1;

    dutchFlag(arr,0,n-1,pivot,eqBound);

    printf("等于区左:%d 等于区右:%d\n", eqBound[0], eqBound[1]);
    printf("划分后数组：");
    for(int k=0;k<n;k++)
    {
        printf("%d ",arr[k]);
    }
    return 0;
}