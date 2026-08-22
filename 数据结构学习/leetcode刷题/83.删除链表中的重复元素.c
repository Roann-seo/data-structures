// 给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。
// 示例 1：


// 输入：head = [1,1,2]
// 输出：[1,2]
// 示例 2：


// 输入：head = [1,1,2,3,3]
// 输出：[1,2,3]


// 提示：

// 链表中节点数目在范围 [0, 300] 内
// -100 <= Node.val <= 100
// 题目数据保证链表已经按升序 排列
#include <stddef.h>
    struct ListNode {
    int val;
    struct ListNode *next;
    };
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head==NULL){
        return NULL;
    }
    //双指针
    struct ListNode*p=head;
    struct ListNode*q=head->next;
    while(q!=NULL){
        if(p->val==q->val){
            q=q->next;
            p->next=q;
            //p->next=q->next;错误
            //找到重复节点时，当前指针 p 不要立刻后移！
            //继续和新的后继节点对比，防止连续重复删不干净。
        }
        else{
            p=q;
            q=q->next;
        }
    }
    return head;
    //单指针
    struct ListNode*cur=head;
    while(cur->next!=NULL){
        if(cur->val==cur->next->val){
            cur->next=cur->next->next;
        }else{
            cur=cur->next;
        }
    }
    return head;
}


int main(){
    // 构造 1->1->2
    struct ListNode n3 = {2, NULL};
    struct ListNode n2 = {1, &n3};
    struct ListNode n1 = {1, &n2};

    struct ListNode *res = deleteDuplicates(&n1);
    for(struct ListNode *p = res; p != NULL; p = p->next){
        printf("%d ", p->val);
    }
    printf("\n");
    return 0;
}
