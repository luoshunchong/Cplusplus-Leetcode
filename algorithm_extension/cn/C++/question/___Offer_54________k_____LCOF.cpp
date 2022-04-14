// @algorithm @lc id=100333 lang=cpp 
// @title er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof


#include <iostream>
#include <vector>
#include <string>
#include <stack>
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
// @test([3,1,4,null,2],1)=4
// @test([5,3,6,2,4,null,null,1],3)=4
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        vector<int> res;
        TreeNode* p = root;
        while (!st.empty() || p) {
            if (p) {
                st.push(p);
                p = p->left;
            }
            else {
                p = st.top();
                st.pop();
                res.push_back(p->val);
                p = p->right;
            }
        }
        return res[res.size() - k];
    }
};