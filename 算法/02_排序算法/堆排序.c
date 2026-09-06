#include<stdio.h>
void swap(int arr[],int *a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

//向上冒泡
void heapInsert(int arr[], int index){
    while(arr[index]>arr[(index-1)/2]){
        //如果当前节点大于父节点，交换两个节点位置
        swap(arr,&arr[index],&arr[(index-1)/2]);
        //然后让节点变成父节点继续往上判断
        index=(index-1)/2;
    }
}
/**
 * heapify 向下调整
 * arr：堆数组
 * index：要向下调整的位置
 * heapSize：堆有效大小
*/
void heapify(int arr[], int index, int heapSize){
    int left=index*2+1;
    while(left<heapSize){
        //说明下边有孩子
        int largest=left;
        if(left+1<heapSize&&arr[left]<arr[left+1]){
            largest=left+1;
        }
        if(arr[index]>=arr[largest]){
            break;
        }
        swap(arr,&arr[index],&arr[largest]);
        index=largest;
        left=index*2+1;
    }
}
void heapsort(int arr[],int n){
    if(arr==NULL||n<=1){
        return;
    }
    for(int i=0;i<n;i++){
        heapInsert(arr,i);
        //先用向上冒泡将数组排成大根堆
    }
    while(n>0){
        //此时最大元素就在根部
        swap(arr,&arr[0],&arr[n-1]);
        //将0位置元素和最后一个元素交换
        n--;
        //说明最后一个位置就排好了
        //将最后一个位置和树断链
        heapify(arr,0,n);
        //把换上来的小数做heapify下沉
    }
    
}
int main(void)
{
    int data[] = {3,1,4,2,7,5};
    int n = sizeof(data)/sizeof(data[0]);

    printf("排序前：");
    for(int i = 0; i < n; i++){
        printf("%d ", data[i]);
    }

    heapsort(data, n);

    printf("\n排序后:");
    for(int i = 0; i < n; i++){
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
//变形：假如说数组里面有一个数改成了？
//想要将其还变成堆的形式
//只需知道？是否>父
//if(?>父){heapinsert}
//if(?<父){heapify}