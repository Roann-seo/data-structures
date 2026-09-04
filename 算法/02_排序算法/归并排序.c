#include<stdio.h>
#include<stdlib.h>
void merge(int arr[],int left,int mid,int right){
    int i=left;
    int j=mid+1;
    int k=0;
    int *temp=(int *)malloc(sizeof(int)*(right-left+1));
    while(i<=mid&&j<=right){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }if(arr[i]>arr[j]){
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }while(j<=right){
        temp[k++]=arr[j++];
    }
    for( k=0;k<right-left+1;k++){
        arr[left+k]=temp[k];
    }
    free(temp);
}
void mergesort(int arr[],int left,int right){
    if(left>=right){
        return ;
    }
    int mid=left+(right-left)/2;
    mergesort(arr,left,mid);
    mergesort(arr,mid+1,right);
    merge(arr,left,mid,right);

}

// 打印数组
void printArr(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int arr[] = {8, 4, 5, 7, 1, 3, 6, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("排序前：");
    printArr(arr, n);

    mergesort(arr, 0, n-1);

    printf("排序后：");
    printArr(arr, n);
    return 0;
}
