// 给定两个以 有序链表 形式记录的训练计划 l1、l2，分别记录了两套核心肌群训练项目编号，请合并这两个训练计划，按训练项目编号 升序 记录于链表并返回。

// 注意：新链表是通过拼接给定的两个链表的所有节点组成的。


// 示例 1：

// 输入：l1 = [1,2,4], l2 = [1,3,4]
// 输出：[1,1,2,3,4,4]
// 示例 2：

// 输入：l1 = [], l2 = []
// 输出：[]
// 示例 3：

// 输入：l1 = [], l2 = [0]
// 输出：[0]
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
        int val;
        struct ListNode *next;
};
struct ListNode* trainningPlan(struct ListNode* l1, struct ListNode* l2) {
    if(l1==NULL&&l2==NULL){
        return NULL;
    }
    struct ListNode*p1=l1;
    struct ListNode*p2=l2;
    struct ListNode*newhead=(struct ListNode*)malloc(sizeof(struct ListNode));
    //使用哨兵是为了防止第一个元素不知道是从l1开始还是l2开始
    newhead->next=NULL;
    //记住一定要将后面置为空
    struct ListNode*tail=newhead;
    //使用tail是为了跟着链表跑，防止最后找不到链表头
    while(p1!=NULL&&p2!=NULL){
        if(p1->val<=p2->val){
            tail->next=p1;
            p1=p1->next;
        }else if(p1->val>p2->val){
            tail->next=p2;
            p2=p2->next;
        }
        tail=tail->next;
    }
    if(p1!=NULL){
        tail->next=p1;
    }
    if(p2!=NULL){
        tail->next=p2;
    }
    struct ListNode*ans=newhead->next;
    //这个指针是为了去掉头节点，从有数据的开始
    free(newhead);
    return ans;
}