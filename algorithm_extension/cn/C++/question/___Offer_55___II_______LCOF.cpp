// @algorithm @lc id=100342 lang=cpp 
// @title ping-heng-er-cha-shu-lcof


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
// @test([3,9,20,null,null,15,7])=true
// @test([1,2,2,3,3,null,null,4,4])=false
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (abs(maxdepth(root->left) - maxdepth(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int maxdepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxdepth(root->left), maxdepth(root->right)) + 1;
    } 
};