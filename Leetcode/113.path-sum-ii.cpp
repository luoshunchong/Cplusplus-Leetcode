// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem113.h"

using namespace std;
// @before-stub-for-debug-end

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
// class Solution {
// private:
//     vector<vector<int>> res;
//     vector<int> tem;

// public:
//     vector<vector<int>> pathSum(TreeNode *root, int sum)
//     {
//         digui(root, sum);
//         return res;
//     }
//     void digui(TreeNode *root, int sum)
//     {
//         if (!root) return;
//         tem.push_back(root->val);
//         sum -= root->val;
//         if (sum == 0 && !root->left && !root->right)
//             res.push_back(tem);
//         digui(root->left, sum);  // 左
//         digui(root->right, sum); // 右
//         tem.pop_back();          // 函数退出之前先弹出当前节点
//     }
// };

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};
        vector<vector<int>> res;
        stack<TreeNode*> st;
        stack<pair<int, vector<int>>> st1;
        st.push(root);
        st1.push(pair<int, vector<int>>(root->val, {root->val}));
        while (!st.empty()) {
            TreeNode* p = st.top();
            st.pop();
            pair<int, vector<int>> pa = st1.top();
            st1.pop();
            if (!p->left && !p->right && pa.first == targetSum) res.push_back(pa.second);
            if (p->left) {
                st.push(p->left);
                vector<int> temp = pa.second;
                temp.push_back(p->left->val);
                st1.push(pair<int, vector<int>>(pa.first + p->left->val, temp));
            }
            if (p->right) {
                st.push(p->right);
                vector<int> temp = pa.second;
                temp.push_back(p->right->val);
                st1.push(pair<int, vector<int>>(pa.first + p->right->val, temp));
            }
        }
        return res;
    }
};
// @lc code=end

