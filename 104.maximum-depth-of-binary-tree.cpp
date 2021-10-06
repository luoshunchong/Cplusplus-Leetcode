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
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int res = 0;
        while (!q.empty())
        {
            int t=q.size();
            for (int i = 0; i < t; ++i)
            {
                TreeNode *N = q.front();
                q.pop();
                if (N->left)
                    q.push(N->left);
                if (N->right)
                    q.push(N->right);
            }
            ++res;
        }
        return res;
    }
};
// @lc code=end

