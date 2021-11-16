/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
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
    // //方案一：采用递归的方式。超时
    // /*
    // 计算了root的四个孙子（左右孩子的孩子）为头结点的子树的情况，
    // 又计算了root的左右孩子为头结点的子树的情况，计算左右孩子的时
    // 候其实又把孙子计算了一遍。
    // */
    // int rob(TreeNode* root) {
    //     if (root == nullptr) return 0;
    //     if (root->left == nullptr && root->right == nullptr) return root->val;
    //     //偷父节点
    //     int val1 = root->val;
    //     if (root->left) val1 += rob(root->left->left) + rob(root->left->right);
    //     if (root->right) val1 += rob(root->right->left) + rob(root->right->right);
    //     //不偷父节点
    //     int val2 = rob(root->left) + rob(root->right);
    //     return max(val1, val2);
    // }

    // //方案二：记忆递归，这次使用一个undered_map去保存结果
    // unordered_map<TreeNode* ,int> umap;
    // int rob(TreeNode* root) {
    //     if (root == nullptr) return 0;
    //     if (root->left == nullptr && root->right == nullptr) return root->val;
    //     if (umap[root]) return umap[root];  //如果umap中已经有记录则直接返回
    //     //偷父节点
    //     int val1 = root->val;
    //     if (root->left) val1 += rob(root->left->left) + rob(root->left->right);
    //     if (root->right) val1 += rob(root->right->left) + rob(root->right->right);
    //     //不偷父节点
    //     int val2 = rob(root->left) + rob(root->right);
    //     umap[root] = max(val1, val2);  //umap中记录一下结果
    //     return max(val1, val2);
    // }

    //方案三：动态规划
    int rob(TreeNode* root) {
        vector<int> res = robTree(root);
        return max(res[0], res[1]);
    }
    //长度为2的数组，偷：1；不偷：0
    vector<int> robTree(TreeNode* cur){
        if (cur == nullptr) return vector<int> {0, 0};
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        //偷cur
        int val1 = cur->val + left[0] + right[0];
        //不偷cur
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        return {val2, val1};
    }
};
// @lc code=end

