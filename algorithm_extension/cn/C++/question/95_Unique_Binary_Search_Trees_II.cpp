// @algorithm @lc id=95 lang=cpp 
// @title unique-binary-search-trees-ii

#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test(3)=[[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
// @test(1)=[[1]]
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
    vector<TreeNode* > res;
    TreeNode* dummyhead = new TreeNode(0);
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        TreeNode* p = dummyhead;
        backtracking(n, 1, p);
        return res;
    }
    void backtracking(int n, int pos, TreeNode* p) {
        if (pos > n) {
            if (check(dummyhead->right)) {
                res.push_back(dummyhead->right);
                // cout << dummyhead->right << endl;
            }
            return ;
        }
        //左子树
        TreeNode* temp1 = new TreeNode(pos);
        p->left = temp1;
        backtracking(n, pos + 1, p->left);
        p->left = nullptr;
        delete temp1;
        //右子树
        TreeNode* temp2 = new TreeNode(pos);
        p->right = temp2;
        backtracking(n, pos + 1, p->right);
        p->right = nullptr;
        delete temp2;
    }
    //判断是不是二叉树搜索树
    bool check(TreeNode* head) {
        if (!head) return true;
        if (head->left && head->val < head->left->val) return false;
        if (head->right && head->val > head->right->val) return false;
        return check(head->left) && check(head->right);
    }
};