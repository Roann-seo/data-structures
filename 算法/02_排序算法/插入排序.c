#include<stdio.h>
//相当于扑克牌
void insertsort(int arr[],int n){
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0&&arr[j]>arr[j+1];j--){
            //往前换换到前一个数比后一个数小再停止
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
}
int main()
{
    int arr[] = {5,2,9,1,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    insertsort(arr, n);

    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
// ## 插入排序核心原理

// 1. 把数组分成：**左边有序区，右边无序区**
// 2. 每次从无序区拿第一个元素，插入到有序区合适位置
// 3. 最好时间复杂度：`O(n)`（数组已经有序）；最坏 / 平均：`O(n²)`
// 4. **稳定排序**：相等元素相对位置不变；空间复杂度`O(1)`原地排序。