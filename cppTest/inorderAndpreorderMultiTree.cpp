#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

vector<TreeNode*> check(vector<int>& preorder, int prel, int prer, vector<int>& inorder, int inol, int inor) {
    vector<TreeNode* > res;
    if (prel > prer || inol > inor) return {};
    int rootVal = preorder[prel];
    //找到在中序遍历中根节点
    vector<int> temp;
    int index = inol;
    for (; index <= inor; ++index) {
        if (inorder[index] == rootVal) {
            temp.push_back(index);
        }
    }
    for (auto i : temp) {
        int inol1 = inol;
        int inor1 = i - 1;
        int inol2 = i + 1;
        int inor2 = inor;
        int prel1 = prel + 1;
        int prer1 = prel + i - inol;
        int prel2 = prel + i - inol + 1;
        int prer2 = prer;
        vector<TreeNode*> left = check(preorder, prel1, prer1, inorder, inol1, inor1);
        vector<TreeNode *> right = check(preorder, prel2, prer2, inorder, inol2, inor2);
        for (auto l : left) {
            for (auto r : right) {
                TreeNode* root = new TreeNode(rootVal);
                root->left = l;
                root->right = r;
                res.push_back(root);
            }
        }
    }
    
    return res;
}

vector<TreeNode*> buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.size() == 0) return {};
    return check(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}


int main() {
    vector<int> preorder = {1,1,2};
    vector<int> inorder = {1,2,1};
    vector<TreeNode*> res= buildTree(preorder, inorder);

    system("pause");
    return 0;
}