#include<stdio.h>
void shellSort(int arr[], int n){
    for(int gap=n/2;gap>0;gap/=2) {
        for(int i=gap;i<n;i++){
        int temp=arr[i];
        int j;
            for( j=i-gap;j>=0&&arr[j]>temp;j-=gap){
            arr[j+gap]=arr[j];
            }
        arr[j+gap]=temp;
        }
    }
    
}
//打印数组
void printArr(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {8, 9, 1, 7, 2, 3, 5, 4, 6, 0};
    int len = sizeof(arr)/sizeof(arr[0]);
    printf("原数组：");
    printArr(arr, len);

    shellSort(arr, len);
    printf("希尔排序后：");
    printArr(arr, len);
    return 0;
}
// 1. **对 gap 的理解误区**
// 误以为`gap = n/2`是数组中间下标；实际 gap 是**分组间隔步长**，不是数组中间位置。`i = gap`不是从数组中间元素开始遍历后半段，而是取**每一组的第二个元素**开始做组内插入。
// 2. **混淆「交换」和「元素后移」，这是最大误区**
// 以为希尔内层循环在做两两交换。

// - 交换：两个变量互相置换，`t=a;a=b;b=t`
// - 标准希尔 / 直接插入：**保存 temp，大元素向后复制覆盖，最后回填 temp**，中间没有交换。

// > 
// > 语法上交换版本可以跑，但是效率差，不是课本标准写法，考试写交换会扣分。

// 3. **不理解为什么插入位置写 `j+gap`，而不是直接用 j**
// 循环结束 j 有可能变成负数，不能直接`arr[j]=temp`，会数组越界。
// 停下后，往回走 gap 步才是空位，`j+gap`才是正确插入位置。

// > 
// > gap=1 时等价直接插入的`j+1`。

// 4. **概念分类混淆**
// 希尔排序属于**插入类排序**，不是交换排序；冒泡、快排才是交换排序。
// 希尔是直接插入排序的优化，gap=1 时完全退化成普通直接插入排序。
// 5. **稳定性概念容易忘**
// 希尔排序是不稳定排序：因为元素可以远距离跳跃挪动，相等元素的相对顺序会被打乱。