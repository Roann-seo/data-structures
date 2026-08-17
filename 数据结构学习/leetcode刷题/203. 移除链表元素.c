// 给你一个链表的头节点 head 和一个整数 val ，
// 请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
// 输入：head = [1,2,6,3,4,5,6], val = 6
// 输出：[1,2,3,4,5]
// 示例 2：

// 输入：head = [], val = 1
// 输出：[]
// 示例 3：

// 输入：head = [7,7,7,7], val = 7
// 输出：[]
#include <stddef.h>
    struct ListNode {
    int val;
    struct ListNode *next;
    };
    struct ListNode* removeElements(struct ListNode* head, int val) {
    if(head==NULL){
        return NULL;
    }
    struct ListNode*dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next=head;
    struct ListNode*p=dummy;
    while(p->next!=NULL){
        if(p->next->val==val){
            p->next=p->next->next;
        }else{
            p=p->next;  
        }
    }
//     只有不删除节点的时候，才能移动指针 p；
// 一旦执行删除操作，p 原地不动，不能前进！
// 为什么错（通俗例子）
// 链表：1 → 6 → 6 → 3，val=6
// p 指向 1，p->next 是第一个 6，满足条件，执行删除
// 链表变为 1 → 6 → 3
// 重点：代码依然执行 p=p->next，p 跑到了第二个 6
// 此时 p->next 是 3，再也检测不到剩下的 6，连续重复节点删不干净
    return dummy->next;
}