#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}; 
};

void print_num(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] ;
    }
    cout << endl;
}

TreeNode* create_tree(vector<int>& vec) {
    vector<TreeNode* > vec1;
    TreeNode* root = nullptr;
    //第一遍遍历将数组中的值，转换成树节点存储在数组中
    for (int i = 0; i < vec.size(); ++i) {
        TreeNode* node = nullptr;
        if (vec[i] != -1) node = new TreeNode(vec[i]);
        vec1.push_back(node);
        if (i == 0) root = node;
    }
    //第二遍遍历，将数组中的树进行构建
    for (int i = 0; i * 2 + 2 < vec1.size(); ++i) {
        if (vec1[i]) {
            vec1[i]->left = vec1[i * 2 + 1];
            vec1[i]->right = vec1[i * 2 + 2];
        }
    }
    return root;
}

vector<int> level_ordered(TreeNode* root) {
    vector<int> res;
    queue<TreeNode* > qu;
    qu.push(root);
    while (!qu.empty()) {
        int qu_size = qu.size();
        for (int i = 0; i < qu_size; ++i) {
            TreeNode* p = qu.front();
            qu.pop();
            res.push_back(p->val);
            if (p->left) qu.push(p->left);
            if (p->right) qu.push(p->right);
        } 
    }
    return res;
}

vector<int> pre_ordered(TreeNode* root) {
    vector<int> res;
    stack<TreeNode* > st;
    TreeNode* p = root;
    while (!st.empty() || p) {
        if (p) {
            st.push(p);
            res.push_back(p->val);
            p = p->left;
        }
        else {
            p = st.top();
            st.pop();
            p = p->right;
        }
    }
    return res;
}

vector<int> order_ordered(TreeNode* root) {
    vector<int> res;
    stack<TreeNode* > st;
    TreeNode* p = root;
    while (!st.empty() || p) {
        if (p) {
            st.push(p);
            p = p->left;
        }
        else {
            p = st.top();
            st.pop();
            res.push_back(p->val);
            p = p->right;
        }
    }
    return res;
}

vector<int> post_ordered(TreeNode* root) {
    vector<int> res;
    stack<TreeNode* > st;
    TreeNode* p = root;
    TreeNode* r = nullptr;
    while (!st.empty() || p) {
        if (p) {
            st.push(p);
            p = p->left;
        }
        else {
            p = st.top();
            if (!p->right || p->right == r) {
                st.pop();
                res.push_back(p->val);
                r = p;
                p = nullptr;
            }
            else {
                p = p->right;
            }
        }
    }
    return res;
}

int main() {
    vector<int> tree = {4, 1, 6, 0, 2, 5, 7, -1, -1, -1, 3, -1, -1, -1, 8};
    //构建一棵树
    TreeNode* root = create_tree(tree);
    //层序遍历
    vector<int> level_order = level_ordered(root);
    //打印
    cout << "层序遍历" << endl;
    print_num(level_order);
    //先序遍历
    vector<int> pre_order = pre_ordered(root);
    //打印
    cout << "先序遍历" << endl;
    print_num(pre_order);
    //中序遍历
    vector<int> order_order = order_ordered(root);
    //打印
    cout << "中序遍历" << endl;
    print_num(order_order);
    //后序遍历
    vector<int> post_order = post_ordered(root);
    //打印
    cout << "后序遍历" << endl;
    print_num(post_order);

    return 0;
}