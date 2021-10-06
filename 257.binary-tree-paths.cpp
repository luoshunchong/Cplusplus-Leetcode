/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    // vector<string> binaryTreePaths(TreeNode *root)
    // { //dfs，迭代
    //     vector<string> res;
    //     stack<TreeNode *> st;
    //     st.push(root);
    //     string path;
    //     path += to_string(root->val);
    //     while (!st.empty())
    //     {
    //         TreeNode *p = st.top();
    //         st.pop();
    //         if (p->left)
    //         {
    //             st.push(p->left);
    //         }
    //         if (p->right)
    //         {
    //             st.push(p->right);
    //         }
    //     }
    //     return res;
    // }

    vector<string> binaryTreePaths(TreeNode *root)
    { //dfs，递归
        vector<string> res;
        dfs(root, "", res);
        return res;
    }
    void dfs(TreeNode *root, string path, vector<string> &res)
    {
        if (root)
        {
            path += to_string(root->val);
            if (!root->left && !root->right)
            {
                res.push_back(path);
            }
            else
            {
                path += "->";
                dfs(root->left, path, res);
                dfs(root->right, path, res);
            }
        }
    }
};
// @lc code=end
