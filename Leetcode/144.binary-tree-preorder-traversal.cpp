/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    
    // vector<int> preorderTraversal(TreeNode* root) {//递归
    //     vector<int> res;
    //     if(!root)
    //     {
    //         return {};
    //     }
    //     Traversal(root,res);
    //     return res;
    // }
    // void Traversal(TreeNode* root,vector<int>& res){
    //     if(!root){
    //         return ;
    //     }
    //     res.push_back(root->val);
    //     Traversal(root->left,res);
    //     Traversal(root->right,res);
    // }
    vector<int> preorderTraversal(TreeNode* root) {//迭代
        vector<int> res;
        if(!root) return {};
        stack<TreeNode* > st;
        st.push(root);
        while(!st.empty()){
            TreeNode* p = st.top();
            st.pop();
            res.push_back(p->val);
            if(p->right) st.push(p->right);
            if (p->left) st.push(p->left);
        }
        return res;
    }
};
// @lc code=end

