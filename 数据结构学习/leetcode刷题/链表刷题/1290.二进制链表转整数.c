// 给你一个单链表的引用结点 head。链表中每个结点的值不是 0 就是 1。
// 已知此链表是一个整数数字的二进制表示形式。

// 请你返回该链表所表示数字的 十进制值 。

// 最高位 在链表的头部。
// 输入：head = [1,0,1]
// 输出：5
// 解释：二进制数 (101) 转化为十进制数 (5)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include<stddef.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
int getDecimalValue(struct ListNode* head) {
    struct ListNode*p=head;
    int ans=0;//用来保存十进制结果
    //从头部开始读，每读进来一个就先将他保存为十进制的个位，
    //然后继续往下读，只要后面还有数据，就将上一个*2+后一位
    //这样只遍历链表一次，时间复杂度\(O(n)\)，空间\(O(1)\)。
    while(p!=NULL){
        ans=ans*2+p->val;
        p=p->next;
    }
    return ans;
}