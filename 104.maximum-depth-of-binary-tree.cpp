/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
    // int maxDepth(TreeNode* root) {//DFS,非递归
    //     if(!root) return 0;
    //     int res=0;
    //     stack<TreeNode*> st;
    //     stack<int> level;//记录当前的层数
    //     st.push(root);
    //     level.push(1);
    //     while(!st.empty()){
    //         TreeNode* p = st.top();
    //         st.pop();
    //         int currlevel = level.top();
    //         level.pop();
    //         res = max(currlevel,res);
    //         if(p->left){
    //             st.push(p->left);
    //             level.push(currlevel+1);
    //         }
    //         if(p->right){
    //             st.push(p->right);
    //             level.push(currlevel+1);
    //         }
    //     }
    //     return res;
    // }

    // int maxDepth(TreeNode *root)
    // { //DFS,递归
    //     if (!root)
    //         return 0;
    //     return max(maxDepth(root->left),maxDepth(root->right))+1;
    // }

    int maxDepth(TreeNode* root) {//BFS,非递归
        if(!root) return 0;
        int res=0;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            int level = qu.size();
            res++;
            for(int i=0;i<level;++i){
                TreeNode* p = qu.front();
                qu.pop();
                if(p->left) qu.push(p->left);
                if(p->right) qu.push(p->right);
            }
        }
        return res;
    }
};
// @lc code=end

