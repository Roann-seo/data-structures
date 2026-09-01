#include<stdio.h>
// 核心思想：相邻两个元素比较，
// 如果前面比后面大，就交换；每一轮把最大的数 “冒泡” 到数组末尾。
void bubbleSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        //外层循环控制轮数最多n-1轮
        int flag=0;
        for(int j=0;j<n-i-1;j++){
            //内层循环控制每次前n-1-i个数两两作比较
            //后面i+1个数已经排好序了
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }
}