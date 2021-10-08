// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem226.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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
    // TreeNode* invertTree(TreeNode* root) {//递归
    //     if(!root) return nullptr;
    //     TreeNode *p = root->left;
    //     root->left = root->right;
    //     root->right = p;
    //     invertTree(root->left);
    //     invertTree(root->right);
    //     return root;
    // }

    // TreeNode *invertTree(TreeNode *root)
    // { //DFS,迭代
    //     if (!root)
    //         return nullptr;
    //     stack<TreeNode*> st;
    //     st.push(root);
    //     while(!st.empty()){
    //         TreeNode* p = st.top();
    //         st.pop();
    //         TreeNode *q = p->left;
    //         p->left = p->right;
    //         p->right = q;
    //         if(p->left) st.push(p->left);
    //         if(p->right) st.push(p->right);
    //     }
    //     return root;
    // }

    TreeNode *invertTree(TreeNode *root)
    { //BFS,迭代
        if (!root)
            return nullptr;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            int level = qu.size();
            for(int i=0;i<level;++i){
                TreeNode* p = qu.front();
                qu.pop();
                TreeNode *q = p->left;
                p->left = p->right;
                p->right = q;
                if(p->left) qu.push(p->left);
                if(p->right) qu.push(p->right);
            }
        }
        return root;
    }
};
// @lc code=end

