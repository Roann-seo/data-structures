// ============ LeetCode 21. 合并两个有序链表 ============
// 难度: 简单
// 标签: 链表 / 双指针
// 链接: https://leetcode.cn/problems/merge-two-sorted-lists/
//
// 题目:
// 将两个升序链表合并为一个新的升序链表并返回。
// 新链表是通过拼接给定的两个链表的所有节点组成的。
//
// 输入: l1 = [1,2,4], l2 = [1,3,4]
// 输出: [1,1,2,3,4,4]
//
// 思路:
//   双指针分别遍历两个链表,每次取较小的节点接入新链表。
// 复杂度:
//   时间 O(m+n),空间 O(1)
// ====================================================
#include <stddef.h>
    struct ListNode {
    int val;
     struct ListNode *next;
    };
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    //建一个虚拟头节点
    struct ListNode*tail=&dummy;//指向头节点的指针
    while(list1!=NULL&&list2!=NULL){
        if(list1->val>=list2->val){
            tail->next=list2;
            list2=list2->next;
        }else{
            tail->next=list1;
            list1=list1->next;
        }
        tail=tail->next;
    }
    if(list1==NULL&&list2!=NULL){
        tail->next=list2;
    }else{
        tail->next=list1;
    }
    return dummy.next;
}