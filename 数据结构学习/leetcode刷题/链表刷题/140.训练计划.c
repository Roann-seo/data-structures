#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
//我想的先反转在取第 cnt 个节点
struct ListNode* trainingPlan(struct ListNode* head, int cnt) {
    struct ListNode*first=NULL;
    struct ListNode*second=head;
    struct ListNode*third;
    while(second!=NULL){
        third=second->next;
        second->next=first;
        first=second;
        second=third;
    }
    for(int i=0;i<cnt-1;i++){
        first=first->next;
    }
    return first;
}

//输入：`[2,4,7,8] cnt=1`
// 你的输出：`[8,7,4,2]`
// 预期输出：`[8]`
//最后还是用快慢指针
struct ListNode* trainingPlan(struct ListNode* head, int cnt) {
    struct ListNode*fast=head;
    struct ListNode*slow=head;
    for(int i=0;i<cnt;i++){
        fast=fast->next;
    }
    while(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
}