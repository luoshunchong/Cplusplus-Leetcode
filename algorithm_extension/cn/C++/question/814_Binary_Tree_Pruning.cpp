// @algorithm @lc id=832 lang=cpp 
// @title binary-tree-pruning

#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([1,null,0,0,1])=[1,null,0,null,1]
// @test([1,0,1,0,0,0,1])=[1,null,1,null,1]
// @test([1,1,0,1,1,0,1,0])=[1,1,0,1,1,null,1]
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
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) return nullptr;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (!left && !right && root->val == 0) return nullptr;
        return root;
    }
};