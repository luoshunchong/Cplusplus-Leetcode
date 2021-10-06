// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem94.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    // vector<int> res;
    // vector<int> inorderTraversal(TreeNode* root) {//递归方法
    //     if(!root){
    //         return {};//当root为空的时候，返回空数组；也是递归的出口
    //     }
    //     inorderTraversal(root->left);//遍历左
    //     res.push_back(root->val);//放到数组中去
    //     inorderTraversal(root->right);//遍历右
    //     return res;
    // }
    vector<int> inorderTraversal(TreeNode *root)
    { //迭代的方法
        if (!root)
            return {};
        vector<int> res;
        stack<TreeNode *> temp;
        TreeNode *p = root;
        while (!temp.empty() || p)
        {
            if (p)
            {
                temp.push(p);
                p = p->left;
            }
            else
            {
                p = temp.top();
                temp.pop();
                res.push_back(p->val);
                p = p->right;
            }
        }
        return res;
    }
};
// @lc code=end
