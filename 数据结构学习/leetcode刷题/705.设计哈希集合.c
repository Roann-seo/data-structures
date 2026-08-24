// 1. `obj->buckets[idx] = xxx;`

// > 
// > 修改**数组里面存的地址值**（头指针本身改了，指向别的节点）

// 2. `obj->buckets[idx]->next = xxx;`

// > 
// > `->next` 是访问节点内部的 next 成员。
// > **不改变头指针存的是谁，只是修改【头节点】内部的 next 字段**。



// 不使用任何内建的哈希表库设计一个哈希集合（HashSet）。

// 实现 MyHashSet 类：

// void add(key) 向哈希集合中插入值 key 。
// bool contains(key) 返回哈希集合中是否存在这个值 key 。
// void remove(key) 将给定值 key 从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。

// 示例：

// 输入：
// ["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
// [[], [1], [2], [1], [3], [2], [2], [2], [2]]
// 输出：
// [null, null, null, true, false, null, true, null, false]

// 解释：
// MyHashSet myHashSet = new MyHashSet();
// myHashSet.add(1);      // set = [1]
// myHashSet.add(2);      // set = [1, 2]
// myHashSet.contains(1); // 返回 True
// myHashSet.contains(3); // 返回 False ，（未找到）
// myHashSet.add(2);      // set = [1, 2]
// myHashSet.contains(2); // 返回 True
// myHashSet.remove(2);   // set = [1]
// myHashSet.contains(2); // 返回 False ，（已移除）
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
    int val;
    struct node*next;
}Node;

typedef struct {
    Node**buckets;
    int bucketsize;
} MyHashSet;

static int getindex(int key,int size){
    return key%size;
}

MyHashSet* myHashSetCreate() {
    MyHashSet*obj=(MyHashSet*)malloc(sizeof(MyHashSet));
    obj->bucketsize=1000;
    obj->buckets=(Node**)calloc(obj->bucketsize,sizeof(Node*));
    return obj;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    int index=getindex(key,obj->bucketsize);
    Node*p=obj->buckets[index];
    while(p!=NULL){
        if(p->val==key){
            return;
            //集合里面不能有重复的
        }
        p=p->next;//p顺着链表往后面查找
    }
    //头插法插入新节点
    Node*newnode=(Node*)malloc(sizeof(Node));
    newnode->val=key;
    //obj->buckets[index]为头节点
    newnode->next=obj->buckets[index];
    //赋值运算符，将新节点后面连着链表里面的数据
    obj->buckets[index]=newnode;
    //头节点指针里面装着新节点地址
}

void myHashSetRemove(MyHashSet* obj, int key) {
    int index=getindex(key,obj->bucketsize);
    Node*cur=obj->buckets[index];
    Node*pre=NULL;
    while(cur!=NULL){
        if(cur->val==key){
            //需要删除数据
            if(pre==NULL){
                //说明是首元素就需要删除，pre=NULL
                obj->buckets[index]=cur->next;
            }else{
                //说明要删除的不是首元素
                pre->next=cur->next;
            }
            free(cur);
            return ;
        }
        pre=cur;
        cur=cur->next;
    }
}

//判断是否存在
bool myHashSetContains(MyHashSet* obj, int key) {
    int index=getindex(key,obj->bucketsize);
    Node*p=obj->buckets[index];
    while(p!=NULL){
        if(p->val==key){
            return true;
        }
        p=p->next;
    }
    return false;
}

void myHashSetFree(MyHashSet* obj) {
    for(int i=0;i<obj->bucketsize;i++){
        Node*p=obj->buckets[i];
        while(p!=NULL){
            Node*temp=p;
            p=p->next;
            free(temp);
            //不能直接释放p，因为释放之后p->next就变成随机值了，链表就断了
        }
    }
    free(obj->buckets);
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);

 * myHashSetRemove(obj, key);

 * bool param_3 = myHashSetContains(obj, key);

 * myHashSetFree(obj);
*/
int main()
{
    MyHashSet* obj = myHashSetCreate();
    myHashSetAdd(obj, 10);
    myHashSetAdd(obj, 20);
    myHashSetRemove(obj,10);
    bool res = myHashSetContains(obj,20);

    myHashSetFree(obj);
    return 0;
}
