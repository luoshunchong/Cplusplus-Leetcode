// @algorithm @lc id=112 lang=cpp 
// @title path-sum


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([5,4,8,11,null,13,4,7,2,null,null,null,1],22)=true
// @test([1,2,3],5)=false
// @test([],0)=false
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
    bool flag = false;
    bool hasPathSum(TreeNode* root, int targetSum) {
        //前序遍历
        if (!root) return false;
        check(root, targetSum, 0);
        return flag;
    }
    void check(TreeNode* root, int targetSum, int sum) {
        if (!root) return ;
        sum += root->val;
        if (!root->left && !root->right) {
            //到达了根节点
            if (sum == targetSum) flag = true;
            return ;
        }
        check(root->left, targetSum, sum);
        check(root->right, targetSum, sum);
    }
};