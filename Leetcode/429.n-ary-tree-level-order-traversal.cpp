// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem429.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};   
        vector<vector<int>> res;
        queue<Node* > qu;
        qu.push(root);
        while (!qu.empty()) {
            int qu_size = qu.size();
            vector<int> temp;
            for (int i = 0; i < qu_size; ++i) {
                Node* p = qu.front();
                qu.pop();
                temp.push_back(p->val);
                for (int j = 0; j < p->children.size(); ++j) {
                    if (p->children[j]) qu.push(p->children[j]);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
// @lc code=end

