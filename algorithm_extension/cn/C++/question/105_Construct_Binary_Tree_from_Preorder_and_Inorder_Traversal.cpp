// @algorithm @lc id=105 lang=cpp 
// @title construct-binary-tree-from-preorder-and-inorder-traversal


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([3,9,20,15,7],[9,3,15,20,7])=[3,9,20,null,null,15,7]
// @test([-1],[-1])=[-1]
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;
        //左闭右闭
        return check(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode* check(vector<int>& preorder, vector<int>& inorder, int prel, int prer, int inol, int inor) {
        if (prel > prer || inol > inor) return nullptr;

        TreeNode* root = new TreeNode(preorder[prel]);

        //找到中序遍历的中间点
        int index = inol;
        for (; index <= inor; ++index) {
            if (inorder[index] == preorder[prel]) break;
        }
        
        //前左
        int prel1 = prel + 1;
        int prer1 = prel + index - inol;
        //前右
        int prel2 = prel + index - inol + 1;
        int prer2 = prer;
        //中左
        int inol1 = inol;
        int inor1 = index - 1;
        //中右
        int inol2 = index + 1;
        int inor2 = inor;

        root->left = check(preorder, inorder, prel1, prer1, inol1, inor1);
        root->right = check(preorder, inorder, prel2, prer2, inol2, inor2);
        return root;
    }
};