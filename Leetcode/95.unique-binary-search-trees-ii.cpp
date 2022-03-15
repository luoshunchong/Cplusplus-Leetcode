// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem95.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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
    vector<TreeNode *> generate(int start, int end)
    {
        //定义递归的出口条件
        if (start > end)
        {
            return {nullptr};
        }
        vector<TreeNode *> alltree;
        for (int i = start; i <= end; ++i)
        {
            vector<TreeNode *> leftTree = generate(start, i - 1);
            vector<TreeNode *> rightTree = generate(i + 1, end);
            for (auto &left : leftTree)
            {
                for (auto &right : rightTree)
                {
                    TreeNode *cu = new TreeNode(i);
                    cu->left = left;
                    cu->right = right;
                    alltree.emplace_back(cu);
                }
            }
        }
        return alltree;
    }
    vector<TreeNode *> generateTrees(int n)
    { //回溯法
        if (!n)
            return {};
        return generate(1, n);
    }
};
// @lc code=end
