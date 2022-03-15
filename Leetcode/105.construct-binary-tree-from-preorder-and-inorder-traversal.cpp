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
    // TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    //     if (preorder.size() == 0)
    //         return NULL; //如果为空，返回NULL
    //     //依次是前序遍历左子树，前序遍历右子树，中序遍历左子树，中序遍历右子树
    //     vector<int> left_pre, right_pre, left_ino, right_ino;
    //     //前序遍历第一个节点一定为根节点
    //     TreeNode *res = new TreeNode(preorder[0]);
    //     //找到中序遍历的根节点
    //     int root = 0;
    //     //遍历找到中序遍历根节点索引值
    //     for (int i = 0; i < inorder.size(); ++i)
    //     {
    //         if (preorder[0] == inorder[i])
    //         {
    //             root = i;
    //             break;
    //         }
    //     }
    //     //利用中序遍历的根节点，对二叉树节点进行归并
    //     for (int i = 0; i < root; ++i)
    //     {
    //         left_ino.push_back(inorder[i]);
    //         left_pre.push_back(preorder[i + 1]); //前序遍历第一个为根节点
    //     }
    //     for (int i = root + 1; i < preorder.size(); ++i)
    //     {
    //         right_ino.push_back(inorder[i]);
    //         right_pre.push_back(preorder[i]);
    //     }
    //     //递归，再对其进行上述所有步骤，即再区分子树的左、右子子数，直到叶节点
    //     res->left = buildTree(left_pre, left_ino);
    //     res->right = buildTree(right_pre, right_ino);
    //     return res;
    // }

    //     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    //     if (preorder.size() == 0 || inorder.size() == 0) return NULL;
    //     return traversal(preorder, inorder);
    // }

    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder) {
        //第一步，判断边界情况
        if (preorder.size() == 0) return NULL;
        //第二步，前序遍历第一个节点就是中序遍历的中间节点，也是二叉树的根节点
        int rootval = preorder[0];
        TreeNode* root = new TreeNode(rootval);
        //第三步，递归出口，判断是不是叶子结点
        if (preorder.size() == 1) return root;
        //第三步，在中序遍历中找切割点
        int deIndex;
        for (deIndex = 0; deIndex < inorder.size() - 1; ++deIndex) {
            if (inorder[deIndex] == rootval) break;
        }
        //第四步，切割中序数组，得到中序左数组，中序右数组
        //采用左闭右开[0, deIndex]
        vector<int> leftinorder(inorder.begin(), inorder.begin() + deIndex);
        //[deIndex, end]
        vector<int> rightinorder(inorder.begin() + deIndex + 1, inorder.end());
        //第五步，切割前序数组，得到前序左数组，前序右数组

        //采用左闭右开[1, leftinorder.size()]
        vector<int> leftpreorder(preorder.begin() + 1, preorder.begin() + 1 + leftinorder.size());
        //[leftinorder.size() + 1, end]
        vector<int> rightpreorder(preorder.begin() + 1 + leftinorder.size(), preorder.end());
        //第六步，递归
        root->left = traversal(leftpreorder, leftinorder);
        root->right = traversal(rightpreorder, rightinorder);

        return root;
    }
};
// @lc code=end

