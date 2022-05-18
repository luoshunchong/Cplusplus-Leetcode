// @algorithm @lc id=543 lang=cpp 
// @title diameter-of-binary-tree


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([1,2,3,4,5])=3
// @test([1,2])=1
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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        check(root);
        return res;
    }
    int check(TreeNode* root) {
        if (!root) return 0;
        int left = check(root->left);
        int right = check(root->right);
        res = max(res, left + right);
        return max(left, right) + 1;
    }
};