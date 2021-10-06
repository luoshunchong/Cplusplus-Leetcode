/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
private:
    vector<vector<int>> res;
    vector<int> tem;

public:
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        digui(root, sum);
        return res;
    }
    void digui(TreeNode *root, int sum)
    {
        if (!root) return;
        tem.push_back(root->val);
        sum -= root->val;
        if (sum == 0 && !root->left && !root->right)
            res.push_back(tem);
        digui(root->left, sum);  // 左
        digui(root->right, sum); // 右
        tem.pop_back();          // 函数退出之前先弹出当前节点
    }
};
// @lc code=end

