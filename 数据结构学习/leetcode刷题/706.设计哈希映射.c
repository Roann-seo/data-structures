// 不使用任何内建的哈希表库设计一个哈希映射（HashMap）。
// **集合只存 key，映射存 key‑value 键值对**。
// 实现 MyHashMap 类：

// MyHashMap() 用空映射初始化对象
// void put(int key, int value) 向 HashMap 插入一个键值对 (key, value) 。如果 key 已经存在于映射中，则更新其对应的值 value 。
// int get(int key) 返回特定的 key 所映射的 value ；如果映射中不包含 key 的映射，返回 -1 。
// void remove(key) 如果映射中存在 key 的映射，则移除 key 和它所对应的 value 。


// 示例：

// 输入：
// ["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
// [[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
// 输出：
// [null, null, null, 1, -1, null, 1, null, -1]

// 解释：
// MyHashMap myHashMap = new MyHashMap();
// myHashMap.put(1, 1); // myHashMap 现在为 [[1,1]]
// myHashMap.put(2, 2); // myHashMap 现在为 [[1,1], [2,2]]
// myHashMap.get(1);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,2]]
// myHashMap.get(3);    // 返回 -1（未找到），myHashMap 现在为 [[1,1], [2,2]]
// myHashMap.put(2, 1); // myHashMap 现在为 [[1,1], [2,1]]（更新已有的值）
// myHashMap.get(2);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,1]]
// myHashMap.remove(2); // 删除键为 2 的数据，myHashMap 现在为 [[1,1]]
// myHashMap.get(2);    // 返回 -1（未找到），myHashMap 现在为 [[1,1]]
#include<stdlib.h>
typedef struct node{
    int val;
    int key;
    struct node*next;
}Node;


typedef struct {
    Node**buckets;
    int bucketsize;
} MyHashMap;


static int getindex(int key,int size){
    return key%size;
}

MyHashMap* myHashMapCreate() {
    MyHashMap*obj=(MyHashMap*)malloc(sizeof(MyHashMap));
    obj->bucketsize=1000;
    obj->buckets=(Node**)calloc(obj->bucketsize,sizeof(Node*));
    return obj;
}
void myHashMapPut(MyHashMap* obj, int key, int value) {
    int index=getindex(key,obj->bucketsize);
    Node*p=obj->buckets[index];
    //先查找key是否存在，存在就更新val
    while(p!=NULL){
        if(p->key==key){
            p->val=value;
            return;
        }
        p=p->next;
    }
    //如果key不存在，就新建头节点
    Node*newnode=(Node*)malloc(sizeof(Node));
    newnode->key=key;
    newnode->val=value;
    newnode->next=obj->buckets[index];
    obj->buckets[index]=newnode;
}

int myHashMapGet(MyHashMap* obj, int key) {
    int index=getindex(key,obj->bucketsize);
    Node*p=obj->buckets[index];
    while(p!=NULL){
        if(p->key==key){
            return p->val;
        }
        p=p->next;
    }
    return -1;
}

void myHashMapRemove(MyHashMap* obj, int key) {
    int index=getindex(key,obj->bucketsize);
    Node*cur=obj->buckets[index];
    Node*pre=NULL;
    while(cur!=NULL){
        if(cur->key==key){
            if(pre==NULL){
                obj->buckets[index]=cur->next;
//                 错误写法：`obj->buckets[index]->next = cur->next;`

// - 修改的是 **cur 节点内部的 next 字段**
// - cur 节点本身还被 `obj->buckets[index]` 指着！链表头仍然是 cur，根本没有把 cur 摘出去。
// 之后执行`free(cur)`，**链表头直接被释放，整个链表直接丢失，内存出错**。
//                 > 区分记忆：

// 1. cur 是**头节点**（pre=NULL）：要修改**桶的指针变量** `obj->buckets[index] = cur->next`，**不要加 ->next**
// 2. cur 是**中间节点**（pre 存在）：修改**前一个节点内部 next** `pre->next = cur->next`，**必须加 ->next**

// 简单一句话

// > 
// > pre 等于 NULL 的时候，cur 就是头节点。
// > 你不能修改 cur 自己身上的 next 把自己删掉；
// > 你得让外面的头指针，不再指向 cur。
            }else{
                pre->next=cur->next;
            }
            free(cur);
            return ;
        }
        pre=cur;
        cur=cur->next;
    }
}

void myHashMapFree(MyHashMap* obj) {
    for(int i=0;i<obj->bucketsize;i++){
        Node*p=obj->buckets[i];
        while(p!=NULL){
            Node*temp=p;
            p=p->next;
            free(temp);
        }
    }
    free(obj->buckets);
    free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);

 * int param_2 = myHashMapGet(obj, key);

 * myHashMapRemove(obj, key);

 * myHashMapFree(obj);
*/

