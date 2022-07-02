// @algorithm @lc id=437 lang=cpp 
// @title path-sum-iii

#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([10,5,-3,3,2,null,11,3,-2,null,1],8)=3
// @test([5,4,8,11,null,13,4,7,2,null,null,5,1],22)=3
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
    int res = 0;
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        vector<int> sum;
        check(root, targetSum, sum);
        return res;
    }
    void check(TreeNode* root, int targetSum, vector<int> sum) {
        if (!root) return ;
        for (auto &num : sum) num += root->val;
        sum.push_back(root->val);
        for (auto num : sum) if (num == targetSum) res++;
        check(root->left, targetSum, sum);
        check(root->right, targetSum, sum);
    }
};