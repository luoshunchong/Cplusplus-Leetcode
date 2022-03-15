// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem257.h"

using namespace std;
// @before-stub-for-debug-end

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
    //     stack<TreeNode *> st;//存放节点
    //     stack<string> st_path;//存放路径
    //     st.push(root);
    //     st_path.push(to_string(root->val)+"");
    //     while (!st.empty())
    //     {
    //         TreeNode *p = st.top();
    //         st.pop();
    //         string path = st_path.top();
    //         st_path.pop();
    //         if(!p->left&&!p->right){
    //             res.push_back(path);
    //         }
    //         if (p->left)
    //         {
    //             st.push(p->left);
    //             st_path.push(path + "->" + to_string(p->left->val));
    //         }
    //         if (p->right)
    //         {
    //             st.push(p->right);
    //             st_path.push(path + "->" + to_string(p->right->val));
    //         }
    //     }
    //     return res;
    // }

    // vector<string> binaryTreePaths(TreeNode *root)
    // { //dfs，递归
    //     vector<string> res;
    //     dfs(root, "", res);
    //     return res;
    // }
    // void dfs(TreeNode *root, string path, vector<string> &res)
    // {
    //     if (root)
    //     {
    //         path += to_string(root->val);
    //         if (!root->left && !root->right)
    //         {
    //             res.push_back(path);
    //         }
    //         else
    //         {
    //             path += "->";
    //             dfs(root->left, path, res);
    //             dfs(root->right, path, res);
    //         }
    //     }
    // }

    vector<string> binaryTreePaths(TreeNode *root)
    { //bfs，迭代
        vector<string> res;
        queue<TreeNode *> qu;
        queue<string> qu1;
        qu.push(root);
        qu1.push(to_string(root->val) + "");
        while (!qu.empty())
        {
            int level = qu.size();
            for (int i = 0; i < level; ++i)
            {
                TreeNode *p = qu.front();
                qu.pop();
                string path = qu1.front();
                qu1.pop();
                if (!p->left && !p->right)
                {
                    res.push_back(path);
                }
                if (p->left)
                {
                    qu.push(p->left);
                    qu1.push(path+"->"+to_string(p->left->val));
                }
                if(p->right){
                    qu.push(p->right);
                    qu1.push(path+"->"+to_string(p->right->val));
                }
            }
        }
        return res;
    }
};
// @lc code=end
