// @algorithm @lc id=113 lang=cpp 
// @title path-sum-ii


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([5,4,8,11,null,13,4,7,2,null,null,5,1],22)=[[5,4,11,2],[5,8,4,5]]
// @test([1,2,3],5)=[]
// @test([1,2],0)=[]
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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};
        vector<int> temp;
        check(root, targetSum, temp, 0);
        return res;
    }
    void check(TreeNode* root, int targetSum, vector<int> temp, int sum) {
        if (!root) return ;
        temp.push_back(root->val);
        sum += root->val;
        if (!root->left && !root->right) {
            if (sum == targetSum) res.push_back(temp);
            return ;
        }
        check(root->left, targetSum, temp, sum);
        check(root->right, targetSum, temp, sum);
    }
};