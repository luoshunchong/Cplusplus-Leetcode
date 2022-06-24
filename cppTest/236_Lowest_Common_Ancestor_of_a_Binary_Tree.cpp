#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

TreeNode* buildTree(vector<int>& nums) {
    //把数组转化成一个树结点数组
    vector<TreeNode*> vec(nums.size(), nullptr);
    TreeNode* root = nullptr;
    for (int i = 0; i < nums.size(); ++i) {
        TreeNode* node = nullptr;
        if (nums[i] != -1) node = new TreeNode(nums[i]);
        vec[i] = node;
        if (i == 0) root = node;
    }
    //再遍历一遍，建树
    for (int i = 0; i * 2 + 2 < vec.size(); ++i) {
        if (vec[i]) {
            vec[i]->left = vec[i * 2 + 1];
            vec[i]->right = vec[i * 2 + 2];
        }
    }
    return root;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //递归的写法
    if (!root) return nullptr;
    if (root->val == p->val || root->val == q->val) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
}

int main () {
    vector<int> nums = {3,5,1,6,2,0,8,-1,-1,7,4};
    TreeNode* root = buildTree(nums);
    TreeNode* p = new TreeNode(6);
    TreeNode* q = new TreeNode(2);
    TreeNode* res = lowestCommonAncestor(root, p, q);
    cout << res->val << endl; 
    return 0;
}