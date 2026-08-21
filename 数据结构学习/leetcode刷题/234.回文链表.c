// 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。
// 如果是，返回 true ；否则，返回 false 。
// 输入：head = [1,2,2,1]
// 输出：true
// 输入：head = [1,2]
// 输出：false
#include <stddef.h>
#include <stdbool.h>
    struct ListNode {
    int val;
    struct ListNode *next;
    };
// bool isPalindrome(struct ListNode* head) {
//     struct ListNode*p=head;
//     struct ListNode*first=NULL;
//     struct ListNode*second=head;
//     struct ListNode*third;
//     while(second!=NULL){
//         third=second->next;
//         second->next=first;
//         first=second;
//         second=third;
//     }
//     struct ListNode*q=first;
//     while(p!=NULL&&q!=NULL){
//         if(p->val!=q->val){
//             return false;
//         }
//         p=p->next;
//         q=q->next;
//         return true;
//     }
// }
//当时想的是将先用p存链表的起始状态，然后将链表反转过来，用q来存链表反转之后
//然后来对比p和q，一致是true,不一致是false
//但是> ❗ 核心根源：
// > 你以为 `p=head` 会保存完整原链表。
// > **但是指针只是存地址，不是拷贝一份链表！**
// > 你反转操作修改节点内部的`next`，会直接修改 p 指向的原始链表。p 只是一个地址别名，不是副本。
// ✅正确做法：**不要反转全部链表，只把链表后半截拿出来反转，
// 前半部分不动，保证前半段链表链条完好，才能拿来对比。**
bool isPalindrome(struct ListNode* head) {
    
    struct ListNode*fast=head;
    struct ListNode*slow=head;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    struct ListNode*first=NULL;
    struct ListNode*second=slow;
    struct ListNode*third;
    while(second!=NULL){
        third=second->next;
        //这个是赋值运算符，将second的下一个赋值给名叫third的里面
        second->next=first;
        //这个是将second的下一个标记为first
        first=second;
        second=third;
    }
    while(head!=NULL&&first!=NULL){
        if(head->val!=first->val){
            return false;
        }
        head=head->next;
        first=first->next;
    }
    return true;
}