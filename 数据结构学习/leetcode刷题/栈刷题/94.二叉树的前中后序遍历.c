// 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
// 输入：root = [1,null,2,3]
// 输出：[1,3,2]
// 示例 2：

// 输入：root = []
// 输出：[]
// 示例 3：

// 输入：root = [1]
// 输出：[1]
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//前序遍历：根左右
//中序遍历：左根右
//后序遍历：左右根
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
//前序遍历
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize=0;
    struct TreeNode**stack=(struct TreeNode**)malloc(sizeof(struct TreeNode*)*501);
    int *res=(int*)malloc(sizeof(int)*501);
    int top=0;
    while(root!=NULL||top>0){
        while(root!=NULL){
            res[(*returnSize)++]=root->val;
            //直接将访问到的根节点存到数组中
            stack[top++]=root;
            root=root->left;
        }
        root=stack[--top];
        root=root->right;
    }
    return res;
}
//中序遍历
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *res=(int*)malloc(sizeof(int)*501);
    *returnSize=0;//c语言只能返回数组指针，不能返回数组
    //returnSize用指针而不用普通变量是因为在内部修改外面也被修改了
    struct TreeNode**stack=(struct TreeNode**)malloc(sizeof(struct TreeNode*)*501);
    int top=0;
    while(root!=NULL||top>0){
        while(root!=NULL){
            stack[top++]=root;
            root=root->left;
        }
        root=stack[--top];
        res[(*returnSize)++]=root->val;
        root=root->right;
    }
    return res;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int *res=(int*)malloc(sizeof(int)*501);
    struct TreeNode**stack=(struct TreeNode**)malloc(sizeof(struct TreeNode*)*501);
    *returnSize=0;
    int top=0;
    struct TreeNode*prev=NULL;
    while(root!=NULL||top>0){
        while(root!=NULL){
            stack[top++]=root;
            root=root->left;
        }
        root=stack[--top];
        if(root->right==NULL||prev==root->right){
            res[(*returnSize)++]=root;
            prev=root;
            root=NULL;
        }else{
            stack[top++]=root;
            //先将自己压回栈再找右孩子
            root=root->right;
            //这样出来的顺序就是右根
        }
    }
    return res;
}