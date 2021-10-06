/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
    // int countNodes(TreeNode* root) {//BFS，迭代
    //     if(!root) return 0;
    //     int res=0;
    //     queue<TreeNode*> qu;
    //     qu.push(root);
    //     while(!qu.empty()){
    //         int level = qu.size();
    //         res+=level;
    //         for(int i=0;i<level;++i){
    //             TreeNode* p = qu.front();
    //             qu.pop();
    //             if(p->left) qu.push(p->left);
    //             if(p->right) qu.push(p->right);
    //         }
    //     }
    //     return res;
    // }

    // int countNodes(TreeNode *root)
    // { //DFS，迭代
    //     if (!root)
    //         return 0;
    //     int res = 0;
    //     stack<TreeNode*> st;
    //     st.push(root);
    //     while(!st.empty()){
    //         TreeNode* p = st.top();
    //         st.pop();
    //         res++;
    //         if(p->left) st.push(p->left);
    //         if(p->right) st.push(p->right);
    //     }
    //     return res;
    // }

    // int countNodes(TreeNode *root)
    // { //递归
    //     if(!root) return 0;
    //     return countNodes(root->left)+countNodes(root->right)+1;
    // }

    //最优的方法
    int countNodes(TreeNode *root)
    {
        /*
        
        */
        
    }
};
// @lc code=end

