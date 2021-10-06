/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    bool isBalanced(TreeNode* root) {//递归
        if(!root) return true;
        bool t = abs(dep(root->left) - dep(root->right)) <= 1 ? true : false;
        return isBalanced(root->left)&&isBalanced(root->right);
    }
    int dep(TreeNode* root){
        if(!root) return 0;
        return max(dep(root->left),dep(root->right))+1;
    }
};
// @lc code=end

