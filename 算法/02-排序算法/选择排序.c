// **思想**：
// 每一轮在未排序区间找到**最小元素的下标**，和未排序区间的第一个元素交换。
// 不像冒泡那样相邻交换，**一轮最多只交换 1 次**。
#include<stdio.h>
void  selectSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[min]>arr[j]){
                min=j;
            }
        }
        if(min!=i){
            int temp=arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
        }
    }
}
int main()
{
    int arr[] = {5,2,9,1,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    selectSort(arr, n);

    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}