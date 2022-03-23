// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem111.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
class Solution {
public:
    // int minDepth(TreeNode* root) {//非递归，BFS
    //     if(!root) return 0;
    //     queue<TreeNode*> qu;
    //     qu.push(root);
    //     int res=0;
    //     while(!qu.empty()){
    //         int level = qu.size();
    //         res++;
    //         for(int i=0;i<level;++i){
    //             TreeNode *p = qu.front();
    //             qu.pop();
    //             if(!p->left&&!p->right) return res;
    //             if(p->left) qu.push(p->left);
    //             if(p->right) qu.push(p->right);
    //         }
    //     }
    //     return res;
    // }

    int getDepth(TreeNode* node) {
        if (node == NULL) return 0;
        int leftDepth = getDepth(node->left);           // 左
        int rightDepth = getDepth(node->right);         // 右
                                                        // 中
        // 当一个左子树为空，右不为空，这时并不是最低点
        if (node->left == NULL && node->right != NULL) { 
            return 1 + rightDepth;
        }   
        // 当一个右子树为空，左不为空，这时并不是最低点
        if (node->left != NULL && node->right == NULL) { 
            return 1 + leftDepth;
        }
        int result = 1 + min(leftDepth, rightDepth);
        return result;
    }

    int minDepth(TreeNode* root) {
        return getDepth(root);
    }
};
// @lc code=end

