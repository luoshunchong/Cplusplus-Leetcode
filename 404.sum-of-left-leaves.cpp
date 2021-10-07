// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem404.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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
class Solution
{
public:
    // int sumOfLeftLeaves(TreeNode* root) {//DFS,迭代
    // //使用两个栈，一个栈存放DFS的节点，另一个栈存放是否为左节点的标志
    //     if(!root) return 0;
    //     int res = 0;
    //     stack<TreeNode*> st;
    //     stack<bool> b;
    //     st.push(root);
    //     b.push(false);
    //     while(!st.empty()){
    //         TreeNode* p = st.top();
    //         st.pop();
    //         bool q = b.top();
    //         b.pop();
    //         if(!p->left&&!p->right&&q){
    //             res+=p->val;
    //         }
    //         if(p->left){
    //             st.push(p->left);
    //             b.push(true);
    //         }
    //         if(p->right){
    //             st.push(p->right);
    //             b.push(false);
    //         }
    //     }

    //     return res;
    // }

    // int sumOfLeftLeaves(TreeNode *root)
    // {   //BFS,迭代
    //     if(!root) return 0;
    //     int res=0;
    //     queue<TreeNode*> qu;
    //     queue<bool> b;
    //     qu.push(root);
    //     b.push(false);
    //     while(!qu.empty()){
    //         int level = qu.size();
    //         for(int i=0;i<level;++i){
    //             TreeNode* p = qu.front();
    //             qu.pop();
    //             bool q = b.front();
    //             b.pop();
    //             if(!p->left&&!p->right&&q){
    //                 res+=p->val;
    //             }
    //             if(p->left){
    //                 qu.push(p->left);
    //                 b.push(true);
    //             }
    //             if(p->right){
    //                 qu.push(p->right);
    //                 b.push(false);
    //             }
    //         }
    //     }
    //     return res;
    // }

    int sumOfLeftLeaves(TreeNode *root)
    { //递归
        if (!root)
            return 0;
        int l = 0;
        if (root->left && !root->left->left && !root->left->right)
        {
            l = root->left->val;
        }
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right) + l;
    }
};
// @lc code=end
