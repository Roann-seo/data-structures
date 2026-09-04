#include<stdio.h>
void swap(int*a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void quickSort(int arr[], int low, int high){
    int pivot=arr[low];
    if(low>high){
        return;
    }
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>=pivot){
            j--;
        }
        swap(&arr[i],&arr[j]);
    }
    if(i==j){
        swap(&pivot,&arr[i]);
    }
    quickSort(arr,low,i-1);
    quickSort(arr,i+1,high);
}
int main()
{
    int nums[] = {8, 3, 6, 2, 9, 1, 5, 7};
    int n = sizeof(nums) / sizeof(nums[0]);

    quickSort(nums, 0, n - 1);

    printf("排序结果：");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }
    return 0;
}