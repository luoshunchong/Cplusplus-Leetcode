#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

TreeNode* BuildTree(vector<int>& nums) {
    vector<TreeNode* > vecTree(nums.size(), nullptr);
    TreeNode* root = nullptr;
    for (int i = 0; i < nums.size(); ++i) {
        TreeNode* node = nullptr;
        if (nums[i] != -1) node = new TreeNode(nums[i]);
        vecTree[i] = node;
        if (i == 0) root = node;
    }
    for (int i = 0; i * 2 + 2 < vecTree.size(); ++i) {
        if (vecTree[i] != nullptr) {
            vecTree[i]->left = vecTree[i * 2 + 1];
            vecTree[i]->right = vecTree[i * 2 + 2];
        }
    }
    return root;
}

TreeNode* LCA(TreeNode* root, int p, int q) {
    if (!root) return nullptr;
    if (root->val == p || root->val == q) return root;
    TreeNode* left = LCA(root->left, p, q);
    TreeNode* right = LCA(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
}
//从root节点开始到x位置的距离
int findNode(TreeNode* root, int x, int level) {
    if (!root) return -1;
    if (root->val == x) return level;
    int left = findNode(root->left, x, level + 1);
    if (left > 0) return left;
    int right = findNode(root->right, x, level + 1);
    if (right > 0) return right;
    return -1;
}

int TwoNodeSum(TreeNode* root, int p, int q) {
    //先用LCA找到最近公共祖先
    TreeNode* parent = LCA(root, p, q);
    //再从公共祖先开始寻找两个节点
    int lenp = findNode(parent, p, 0);
    int lenq = findNode(parent, q, 0);
    return lenp + lenq;
}

int main() {
    vector<int> nums = {1,2,3,4,5,6,7,8,-1,-1,9}; //使用-1表示空节点
    //建树
    TreeNode* root = BuildTree(nums);
    int p = 2, q = 7;
    int res = TwoNodeSum(root, p, q);
    cout << p << "和" << q << "的最短路径是：" << res << endl;
    return 0;
}