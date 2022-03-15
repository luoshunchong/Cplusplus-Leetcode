/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {//非递归，BFS
        if(!root) return 0;
        queue<TreeNode*> qu;
        qu.push(root);
        int res=0;
        while(!qu.empty()){
            int level = qu.size();
            res++;
            for(int i=0;i<level;++i){
                TreeNode *p = qu.front();
                qu.pop();
                if(!p->left&&!p->right) return res;
                if(p->left) qu.push(p->left);
                if(p->right) qu.push(p->right);
            }
        }
        return res;
    }
};
// @lc code=end

