/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
class Solution
{
public:
    // int findBottomLeftValue(TreeNode* root) {//BFS,迭代
    //     if(!root) return 0;
    //     int res=0;
    //     queue<TreeNode*> qu;
    //     qu.push(root);
    //     while(!qu.empty()){
    //         int level = qu.size();
    //         for(int i=0;i<level;++i){
    //             TreeNode* p = qu.front();
    //             qu.pop();
    //             if(i==0) res = p->val;
    //             if(p->left) qu.push(p->left);
    //             if(p->right) qu.push(p->right);
    //         }
    //     }
    //     return res;
    // }

    // int findBottomLeftValue(TreeNode *root)
    // { //DFS,迭代
    //     if (!root)
    //         return 0;
    //     int res = 0;
    //     int max_level = -1; //保存最大层数,初始值最好设置为-1
    //     stack<TreeNode *> st;
    //     stack<int> l; //保存层数
    //     st.push(root);
    //     l.push(0);
    //     while (!st.empty())
    //     {
    //         TreeNode *p = st.top();
    //         st.pop();
    //         int level = l.top();
    //         l.pop();
    //         if (level > max_level)
    //         {
    //             res = p->val;
    //         }
    //         max_level = max(max_level, level);
    //         if (p->right) //注意顺序
    //         {
    //             st.push(p->right);
    //             l.push(level + 1);
    //         }
    //         if (p->left)
    //         {
    //             st.push(p->left);
    //             l.push(level + 1);
    //         }
    //     }
    //     return res;
    // }

    int res = -1;
    int level = -1; //层数
    int findBottomLeftValue(TreeNode *root)
    { //DFS,递归
        getleftnumber(root, 0);
        return res;
    }
    void getleftnumber(TreeNode *root, int num)
    {
        if (!root)
            return;
        if (num > level)
        {
            level = num;
            res = root->val;
        }
        getleftnumber(root->left, num + 1);
        getleftnumber(root->right, num + 1);
    }
};
// @lc code=end
