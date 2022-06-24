// @algorithm @lc id=236 lang=cpp 
// @title lowest-common-ancestor-of-a-binary-tree


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([3,5,1,6,2,0,8,null,null,7,4],5,1)=3
// @test([3,5,1,6,2,0,8,null,null,7,4],5,4)=5
// @test([1,2],1,2)=1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //递归的写法
        if (!root) return nullptr;
        if (root->val == p->val || root->val == q->val) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }
};