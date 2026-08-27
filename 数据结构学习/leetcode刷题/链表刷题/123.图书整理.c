// 书店店员有一张链表形式的书单，每个节点代表一本书，
// 节点中的值表示书的编号。为更方便整理书架，店员需要将书单倒过来排列，
// 就可以从最后一本书开始整理，逐一将书放回到书架上。请倒序返回这个书单链表。
// 示例 1：

// 输入：head = [3,6,4,1]

// 输出：[1,4,6,3]
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stddef.h>
struct ListNode {
    int val;
 struct ListNode *next;
};
int* reverseBookList(struct ListNode* head, int* returnSize) {
    struct ListNode*first=NULL;
    struct ListNode*second=head;
    struct ListNode*third;
    while(second!=NULL){
        third=second->next;
        second->next=first;
        first=second;
        second=third;
    }
    int count=0;
    struct ListNode*p=first;
    while(p!=NULL){
        p=p->next;
        count++;
    }
    *returnSize=count;
    int *arr=(int*)malloc(sizeof(int)*count);
    p=first;
    for(int i=0;i<count;i++){
        arr[i]=p->val;
        p=p->next;
    }
    return arr;
}
//这道题不是返回反转链表，是：把链表全部反转，取出每个节点 val，存进动态开辟的 int 数组返回。