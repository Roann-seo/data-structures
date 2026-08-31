// 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。

// 返回删除后的链表的头节点。

// 示例 1：

// 输入：head = [4,5,1,9], val = 5
// 输出：[4,1,9]
// 解释：给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
// 示例 2：

// 输入：head = [4,5,1,9], val = 1
// 输出：[4,5,9]
// 解释：给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include<stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* deleteNode(struct ListNode* head, int val) {
    struct ListNode*dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next=head;
    struct ListNode*pre=dummy;
    struct ListNode*p=head;
    while(p!=NULL){
        if(p->val==val){
            pre->next=p->next;
            break;
        }
        pre=p;
        p=p->next;
    }
    return dummy->next;
}
// 错误代码
// struct ListNode* deleteNode(struct ListNode* head, int val) {
//     struct ListNode* p=head;
//     while(p!=NULL){
//         if(p->val!=val){
//             p=p->next;
//         }
//         else{
//             struct ListNode* cur=p;
//             struct ListNode* pre;
//             cur=pre->next;   // ❌ pre没有赋值，野指针！
//             pre->next=cur->next;
//         }
//     }
// }
// ## 1. 致命错误：`pre` 指针完全没赋值

// 你直接写 `cur = pre->next;`，`pre` 根本没有存上一个节点地址，这是**野指针**，直接运行崩溃。

// > 
// > pre 的作用：保存 p 的前一个结点，你代码里完全没有更新 pre。

// ## 2. 头节点就是要删除节点的情况没处理

// 比如链表 `[5,1,2]`，要删`val=5`，要直接返回`head->next`，你的代码处理不了。

// ## 3. 删除成功之后没有 break

// 找到目标节点删除完，还会继续循环往下跑。

// ## 4. 函数没有 return 返回头节点，语法错误

// 函数返回类型是`struct ListNode*`，你代码最后没有`return`。