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


// 编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。

// 示例1：

//  输入：[1, 2, 3, 3, 2, 1]
//  输出：[1, 2, 3]
// 示例2：

//  输入：[1, 1, 1, 1, 2]
//  输出：[1, 2]
//区分上面
//上面链表表示有序的，而这个题目是无序的
// 1. **有序链表 deleteDuplicates**：重复只会紧紧相邻，相等时 q 可以直接跳走，p 也可以移动。
// 2. **无序链表 removeDuplicateNodes**：p 固定不动作为基准，q 要一直留在 p 后方，
// **反复删除 q 的后继节点，q 只有不重复的时候才往前走**.






struct ListNode* removeDuplicateNodes(struct ListNode* head) {
    if(head==NULL){
        return NULL;
    }
    struct ListNode*p=head;
    while(p!=NULL){
        struct ListNode*q=p;
        while(q->next!=NULL){
            if(p->val==q->next->val){
                q->next=q->next->next;
                //删除了q->next；让q链表里面的next直接指向q->next->next
            }else{
                q=q->next;
                //q继续往后移动
            }
        }
        p=p->next;
        //与已经排好序的链表不一样
        //这个需要一个一个p与之对比
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
