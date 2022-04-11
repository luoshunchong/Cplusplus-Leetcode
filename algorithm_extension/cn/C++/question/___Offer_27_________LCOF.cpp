// @algorithm @lc id=100288 lang=cpp 
// @title er-cha-shu-de-jing-xiang-lcof


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
// @test([4,2,7,1,3,6,9])=[4,7,2,9,6,3,1]
// @test([4,2,7,1,3,6,9])=[4,7,2,9,6,3,1]
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root) return nullptr;
        swap(root->left, root->right);
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};