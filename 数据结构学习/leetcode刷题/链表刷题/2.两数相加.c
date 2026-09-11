// 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

// 请你将两个数相加，并以相同形式返回一个表示和的链表。

// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
// 输入：l1 = [2,4,3], l2 = [5,6,4]
// 输出：[7,0,8]
// 解释：342 + 465 = 807.
// 示例 2：

// 输入：l1 = [0], l2 = [0]
// 输出：[0]
// 示例 3：

// 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// 输出：[8,9,9,9,0,0,0,1]
#include <stdio.h>
#include <stdlib.h>
struct ListNode {
        int val;
        struct ListNode *next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode*p1=l1;
    struct ListNode*p2=l2;
    struct ListNode*dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next=NULL;
    struct ListNode*p=dummy;
    int cur=0;
    int sum=0;
    int cur_val=0;
    while(p1!=NULL||p2!=NULL||cur!=0){
        //不仅要保证两个链表遍历完，还要保证进位是0，如果是一需要在开辟空间
        int v1=(p1!=NULL)?p1->val:0;
        int v2=(p2!=NULL)?p2->val:0;
        sum=v1+v2+cur;
        cur=sum/10;//进位
        cur_val=sum%10;//这个为当前位置上的数
        // if(p1->val+p2->val<10){
        //     sum=p1->val+p2->val;
        //     //链表不能直接给p->val写值，必须malloc创造新结点，把新节点挂到p->next上
            
        // }else{
        //    cur=(p1->val+p2->val)/10;
        //    sum=(p1->val+p2->val)%10;
        //    p=p->next;
        //    p->val=p1->next->val+p2->next->val+1;
        // }
        // p=p->next;
        struct ListNode*new_node=(struct ListNode*)malloc(sizeof(struct ListNode));
        new_node->val=cur_val;
        new_node->next=NULL;
        p->next=new_node;
        p=p->next;
        if(p1!=NULL){
            p1=p1->next;
        }
        if(p2!=NULL){
            p2=p2->next;
        }
    }
    return dummy->next;
}