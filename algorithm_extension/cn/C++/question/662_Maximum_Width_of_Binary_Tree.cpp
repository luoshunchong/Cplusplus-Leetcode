// @algorithm @lc id=662 lang=cpp 
// @title maximum-width-of-binary-tree


#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "algm/algm.h"
using namespace std;
// @test([1,3,2,5,3,null,9])=4
// @test([1,3,2,5,null,null,9,6,null,7])=7
// @test([1,3,2,5])=2
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
    int widthOfBinaryTree(TreeNode* root) {
        //层序遍历
        int res = 0;
        if (!root) return 0;
        queue<pair<TreeNode*, int> > qu;
        qu.push({root, 0});
        while (!qu.empty()) {
            int len_size = qu.size(), start = qu.front().second, end = qu.back().second;
            res = max(res, end - start + 1);
            for (int i = 0; i < len_size; ++i) {
                pair<TreeNode*, int> p = qu.front();
                qu.pop();
                if (p.first->left) qu.push({p.first->left, (p.second * 2) - start * 2});
                if (p.first->right) qu.push({p.first->right, (p.second * 2 + 1) - start * 2});
            }
        }
        return res;
    }
};