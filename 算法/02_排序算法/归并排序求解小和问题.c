#include<stdio.h>
#include<stdlib.h>
long long merge(int arr[],int left,int mid,int right){
    int i=left;
    int j=mid+1;
    int k=0;
    int *temp=(int *)malloc(sizeof(int)*(right-left+1));
    long long smallsum=0;
    while(i<=mid&&j<=right){
        if(arr[i]<arr[j]){
            smallsum+=arr[i]*(right-j+1);
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }while(j<=right){
        temp[k++]=arr[j++];
    }
    for(k=0;k<right-left+1;k++){
        arr[left+k]=temp[k];
    }
    free(temp);
    return smallsum;
}
long long mergeSortSmallSum(int arr[],int left,int right){
    if(left>=right){
        return 0;
    }
    int mid=left+(right-left)/2;
    long long leftsum=mergeSortSmallSum(arr,left,mid);
    long long rightsum=mergeSortSmallSum(arr,mid+1,right);
    long long crosssum=merge(arr,left,mid,right);
    return leftsum+rightsum+crosssum;
}
int main(void)
{
    int arr[] = {1,3,4,2,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    long long ans = mergeSortSmallSum(arr, 0, n-1);
    printf("小和 = %lld\n", ans);
    return 0;
}