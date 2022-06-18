#include <iostream>
#include <vector>

using namespace std;


 //Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        // 构造闭区间 [1, n] 组成的 BST
        return backtracking(1, n);
    }
    /* 构造闭区间 [left, right] 组成的 BST */
    vector<TreeNode*> backtracking(int left, int right) {
        vector<TreeNode*> res;
        // base case
        if (left > right) {
            res.push_back(nullptr);
            return res;
        }
        // 1、穷举 root 节点的所有可能。
        for (int i = left; i <= right; ++i) {
            // 2、递归构造出左右子树的所有合法 BST。
            vector<TreeNode*> leftTree = backtracking(left, i - 1);
            vector<TreeNode*> rightTree = backtracking(i + 1, right);
            // 3、给 root 节点穷举所有左右子树的组合。
            for (auto a : leftTree) {
                for (auto b : rightTree) {
                    // i 作为根节点 root 的值
                    TreeNode* root = new TreeNode(i);
                    root->left = a;
                    root->right = b;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};

int main () {
    Solution a;
    vector<TreeNode* > res = a.generateTrees(3);
    return 0;
}