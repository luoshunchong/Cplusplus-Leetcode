/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // bool isSymmetric(TreeNode* root) {//递归
    //     return check(root,root);
    // }
    // bool check(TreeNode* left,TreeNode* right){
    //     if(left==nullptr&&right==nullptr) return true;
    //     if(left==nullptr||right==nullptr||left->val!=right->val){
    //         return false;
    //     }
    //     return check(left->left,right->right)&&check(left->right,right->left);
    // }

    // bool isSymmetric(TreeNode *root)
    // { //迭代，栈
    //     if(!root) return true;
    //     if(!root->left&&!root->right) return true;
    //     if(!root->left||!root->right) return false;
    //     stack<TreeNode*> stleft;
    //     stack<TreeNode*> stright;
    //     stleft.push(root->left);
    //     stright.push(root->right);
    //     while(!stleft.empty()&&!stright.empty()){
    //         TreeNode* left = stleft.top();
    //         stleft.pop();
    //         TreeNode* right = stright.top();
    //         stright.pop();
    //         if(left->val!=right->val){
    //             return false;
    //         }
    //         //判断左边入栈与否
    //         if(left->left&&right->right){
    //             stleft.push(left->left);
    //             stright.push(right->right);
    //         }
    //         else if(left->left&&!right->right){
    //             return false;
    //         }
    //         else if(!left->left&&right->right){
    //             return false;
    //         }
    //         //判断右边入栈与否
    //         if(left->right&&right->left){
    //             stleft.push(left->right);
    //             stright.push(right->left);
    //         }
    //         else if (left->right && !right->left)
    //         {
    //             return false;
    //         }
    //         else if (!left->right && right->left)
    //         {
    //             return false;
    //         }
    //     }
    //     if(stleft.empty()&&stright.empty()){
    //         return true;
    //     }else{
    //         return false;
    //     }
            
    // }

    bool isSymmetric(TreeNode *root)
    { //迭代，队列
        if(!root) return true;
        queue<TreeNode*> qu;
        qu.push(root->left);
        qu.push(root->right);
        while(!qu.empty()){
            TreeNode* left = qu.front();
            qu.pop();
            TreeNode* right = qu.front();
            qu.pop();
            if(left==nullptr&&right==nullptr) continue;
            if(left==nullptr||right==nullptr||left->val!=right->val){
                return false;
            }
            qu.push(left->left);
            qu.push(right->right);
            qu.push(left->right);
            qu.push(right->left);
        }
        return true;
    }
};
// @lc code=end

