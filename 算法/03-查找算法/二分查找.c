#include<stdio.h>

int binarySearch(int arr[], int n, int key){
    int left=0;
    int right=n-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(key>arr[mid]){
            left=mid+1;
        }else if(key<arr[mid]){
            right=mid-1;
        }else{
            return mid;
        }
    }
    return -1;
}
int main(void)
{
    int arr[] = {1,3,5,7,9,11,13};
    int len = sizeof(arr)/sizeof(arr[0]);
    int target = 7;

    int index = binarySearch(arr, len, target);
    if(index != -1)
    {
        printf("找到 %d,下标 = %d\n",target, index);
    }
    else
    {
        printf("未找到该元素\n");
    }
    return 0;
}