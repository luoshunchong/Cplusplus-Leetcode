// @algorithm @lc id=100289 lang=cpp 
// @title dui-cheng-de-er-cha-shu-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// @test([1,2,2,3,4,4,3])=true
// @test([1,2,2,null,3,null,3])=false
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return check(root->left, root->right);
    }
    bool check(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (!a || !b) return false;
        if (a->val != b->val) return false;
        return check(a->left, b->right) && check(a->right, b->left);
    }
};