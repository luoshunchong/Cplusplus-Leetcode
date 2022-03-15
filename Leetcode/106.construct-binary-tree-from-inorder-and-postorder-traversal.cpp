/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
private:
    int postIndex;                    // 记录后序遍历中根结点的位置
    unordered_map<int, int> indexMap; // 记录中序遍历中结点值的下标位置
public:
    // 后序遍历：左 右 根       中序遍历：左 根 右
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        // 从后序遍历的最后一个元素开始
        postIndex = postorder.size() - 1; // 获取后序遍历序列中最后一个元素的位置

        // 建立（中序遍历的结点值，在中序遍历序列中的位置）键值对的哈希表
        int idx = 0;
        for (int val : inorder)
        {
            indexMap[val] = idx++;
        }
        return helper(0, inorder.size() - 1, inorder, postorder);
    }

    // inLeft表示中序遍历中当前结点的左子树，inRight表示中序遍历中当前结点的右子树
    TreeNode *helper(int inLeft, int inRight, vector<int> &inorder, vector<int> &postorder)
    {

        if (inLeft > inRight)
        { // 如果没有结点构造二叉树了，就结束
            return nullptr;
        }

        // 选择postIndex位置的元素作为当前子树的根结点
        int root_val = postorder[postIndex];     // 从后序遍历序列中选择当前子树根结点的值
        TreeNode *root = new TreeNode(root_val); // 创建结点

        // 根据root所在位置分成左右两棵子树
        int index = indexMap[root_val]; // 在中序遍历的序列中，以index为基准，分为左右两棵子树
        /*
                  后序遍历中的当前的结点已经生成，并且添加到树中，
                  下标减一是为了继续在后序遍历中找到子树的根结点，
                  注意在后序遍历中寻找根结点是从后往前找！
        */
        postIndex--; // 下标减一

        // 构造右子树
        root->right = helper(index + 1, inRight, inorder, postorder);
        // 构造左子树
        root->left = helper(inLeft, index - 1, inorder, postorder);
        return root;
    }
};
// @lc code=end

