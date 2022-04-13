// @algorithm @lc id=100307 lang=cpp 
// @title xu-lie-hua-er-cha-shu-lcof


#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include "algm/algm.h"
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
//前序遍历
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        stack<TreeNode*> st;
        string res = "";
        TreeNode* p = root;
        while (!st.empty() || p) {
            if (p) {
                st.push(p);
                res += to_string(p->val);
                res += ',';
                p = p->left;
            }
            else {
                res += "#";
                res += ',';
                p = st.top();
                st.pop();
                p = p->right;
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return nullptr;
        string temp = "";
        queue<string> qu;
        for (int i = 0; i < data.size(); ++i) {
            if (data[i] == ',') {
                qu.push(temp);
                temp = "";
            }
            else {
                temp += data[i];
            }
        }
        return check(qu);
    }
    TreeNode* check(queue<string>& qu) {
        if (qu.size() == 0) return nullptr;
        if (qu.front() == "#") {
            qu.pop();
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(qu.front()));
        qu.pop();
        root->left = check(qu);
        root->right = check(qu);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));