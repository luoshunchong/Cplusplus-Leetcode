/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0)
            return NULL; //如果为空，返回NULL
        //依次是前序遍历左子树，前序遍历右子树，中序遍历左子树，中序遍历右子树
        vector<int> left_pre, right_pre, left_ino, right_ino;
        //前序遍历第一个节点一定为根节点
        TreeNode *res = new TreeNode(preorder[0]);
        //找到中序遍历的根节点
        int root = 0;
        //遍历找到中序遍历根节点索引值
        for (int i = 0; i < inorder.size(); ++i)
        {
            if (preorder[0] == inorder[i])
            {
                root = i;
                break;
            }
        }
        //利用中序遍历的根节点，对二叉树节点进行归并
        for (int i = 0; i < root; ++i)
        {
            left_ino.push_back(inorder[i]);
            left_pre.push_back(preorder[i + 1]); //前序遍历第一个为根节点
        }
        for (int i = root + 1; i < preorder.size(); ++i)
        {
            right_ino.push_back(inorder[i]);
            right_pre.push_back(preorder[i]);
        }
        //递归，再对其进行上述所有步骤，即再区分子树的左、右子子数，直到叶节点
        res->left = buildTree(left_pre, left_ino);
        res->right = buildTree(right_pre, right_ino);
        return res;
    }
};
// @lc code=end

