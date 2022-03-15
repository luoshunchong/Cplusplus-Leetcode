// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem145.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 */

// @lc code=start
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
class Solution
{
public:
    // vector<int> res;
    // vector<int> postorderTraversal(TreeNode* root) {//递归,方式一
    //     if(!root) return {};
    //     postorderTraversal(root->left);
    //     postorderTraversal(root->right);
    //     res.push_back(root->val);
    //     return res;
    // }

    // vector<int> res;
    // vector<int> postorderTraversal(TreeNode *root)
    // { //递归，方式二
    //     if (!root)
    //         return {};
    //     Traversal(root, res);
    //     return res;
    // }
    // void Traversal(TreeNode *root, vector<int> &res)
    // {
    //     if (!root)
    //         return;
    //     Traversal(root->left, res);
    //     Traversal(root->right, res);
    //     res.push_back(root->val);
    // }

    vector<int> postorderTraversal(TreeNode *root)
    { //迭代
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* p = root;
        TreeNode* r = nullptr;
        while(!st.empty()||p){
            if(p){
                st.push(p);
                p = p->left;
            }
            else{
                p = st.top();
                if(!p->right||p->right==r){
                    st.pop();
                    res.push_back(p->val);
                    r = p;
                    p = nullptr;
                }
                else{
                    p = p->right;
                }
            }
        }
        return res;
    }
};
// @lc code=end
