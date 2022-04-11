// @algorithm @lc id=100287 lang=cpp 
// @title shu-de-zi-jie-gou-lcof


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
// @test([1,2,3],[3,1])=false
// @test([3,4,5,1,2],[4,1])=true
class Solution {
public:
    bool flag = false;
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!B || !A) return false;
        //找到与树B相同根节点
        pre(A, B);
        return flag;
    }
    void pre(TreeNode* A, TreeNode* B) {
        if (!A) return ;
        if (A->val == B->val) {
            //判断树B是不是树A的子结构
            bool temp = check(A, B);
            if (temp) flag = true;
        }
        pre(A->left, B);
        pre(A->right, B);
    }
    bool check(TreeNode* A, TreeNode* B) {
        if (!B) return true;
        if (!A) return false;
        if (A->val != B->val) return false;
        return check(A->left, B->left) && check(A->right, B->right);

    }
};