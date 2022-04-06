// @algorithm @lc id=106 lang=cpp 
// @title construct-binary-tree-from-inorder-and-postorder-traversal


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([9,3,15,20,7],[9,15,7,20,3])=[3,9,20,null,null,15,7]
// @test([-1],[-1])=[-1]
// @test([2,1],[2,1])=[1,2]

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //判断边界
        if (postorder.size() == 0) return nullptr;
        return check(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    TreeNode* check(vector<int>& inorder, vector<int>& postorder, int inol, int inor, int posl, int posr) {
        if (inol > inor || posl > posr) return nullptr;
        //后序遍历的最后一个元素就是
        TreeNode* root = new TreeNode(postorder[posr]);

        // if ((posr - posl + 1) == 1) return root;

        //找到中序遍历的中间点
        int index = inol;
        for (; index <= inor; ++index) {
            if (inorder[index] == postorder[posr]) break;
        }
        
        //切割数组
        //中序左
        int inol1 = inol;
        int inor1 = index - 1;
        //中序右
        int inol2 = index + 1;
        int inor2 = inor;
        //后序左
        int posl1 = posl;
        int posr1 = posl + index - inol - 1;
        //后序右
        int posl2 = posl + index - inol;
        int posr2 = posr - 1;

        root->left = check(inorder, postorder, inol1, inor1, posl1, posr1);
        root->right = check(inorder, postorder, inol2, inor2, posl2, posr2);
        return root;
    }
};