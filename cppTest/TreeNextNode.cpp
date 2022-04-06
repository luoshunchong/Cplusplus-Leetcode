#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(nullptr), right(nullptr){};
};

TreeNode* buildTree(string s) {
    vector<TreeNode*> temp;
    TreeNode* root = nullptr;
    for (int i = 0; i < s.size(); ++i) {
        TreeNode* p = nullptr;
        if (s[i] != '#') p = new TreeNode(s[i]);
        temp.push_back(p);
        if (i == 0) root = p;
    }
    for (int i = 0; i * 2 + 2 < temp.size(); ++i) {
        if (temp[i]) {
            temp[i]->left = temp[i * 2 + 1];
            temp[i]->right = temp[i * 2 + 2];
        }
    }
    return root;
} 

TreeNode* findNextNode(TreeNode* root, char target) {
    if (!root) return nullptr;
    //先找到这个节点
    //前序遍历
    stack<TreeNode*> st;
    TreeNode* p = root;
    TreeNode* temp = nullptr;
    while (!st.empty() || p) {
        if (p) {
            if (p->val == target) {
                temp = p;
                break;
            }
            st.push(p);
            p = p->left;
        }
        else {
            p = st.top();
            st.pop();
            p = p->right;
        }
    }
    if (!temp) return nullptr;

    TreeNode* p1 = nullptr;
    //情况二
    if (temp->right) {
        TreeNode* pR = temp->right;
        while (pR->left) pR = pR->left;
        p1 = pR;
    }
    else if (temp->)
}

int main() {
    //层序遍历
    string s = "abcdefg##hi";
    //构建二叉树
    TreeNode* root = buildTree(s);
    //找出中序遍历的下一个节点
    TreeNode* res = findNextNode(root, 'a');
    cout << res->val << endl;

    return 0;
}