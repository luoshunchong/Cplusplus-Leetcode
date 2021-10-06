/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode *> q;
        if (root == nullptr)
            return {};
        q.push(root);
        while (!q.empty())
        {
            int t = q.size();
            vector<int> tem;
            for (int i = 0; i < t; ++i)
            {
                TreeNode *N = q.front();
                q.pop();
                tem.push_back(N->val);
                if (N->left)
                    q.push(N->left);
                if (N->right)
                    q.push(N->right);
            }
            res.push_back(tem);
        }
        return res;
    }
};
// @lc code=end

