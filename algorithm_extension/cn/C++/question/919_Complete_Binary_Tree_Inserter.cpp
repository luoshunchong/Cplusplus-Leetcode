// @algorithm @lc id=955 lang=cpp 
// @title complete-binary-tree-inserter
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class CBTInserter {
public:
    TreeNode* t = nullptr;
    TreeNode* node = nullptr;
    CBTInserter(TreeNode* root) {
        t = root;
        node = root;
    }
    
    int insert(int val) {
        TreeNode* p = check(node);
        cout << p->val << endl;
        TreeNode* p1 = new TreeNode(val);
        if (!p->left) p->left = p1;
        else p->right = p1;
        return p->val;
    }
    
    TreeNode* get_root() {
        return t;
    }
    TreeNode* check(TreeNode* root) {
        //层序遍历
        queue<TreeNode*> qu;
        qu.push(root);
        TreeNode* temp = nullptr;
        while (!qu.empty()) {
            int qu_size = qu.size();
            for (int i = 0; i < qu_size; ++i) {
                TreeNode* p = qu.front();
                qu.pop();
                if (!temp && (p->left || p->right)) temp = p;
                if (p->left) qu.push(p->left);
                if (p->right) qu.push(p->right);
            }
        }
        return temp;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);

    CBTInserter *obj = new CBTInserter(root);
    int param_1 = obj->insert(3);
    int param_2 = obj->insert(4);
    TreeNode* param_3 = obj->get_root();
    return 0;
}