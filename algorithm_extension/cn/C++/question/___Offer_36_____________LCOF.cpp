// @algorithm @lc id=100305 lang=cpp 
// @title er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof


#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "algm/algm.h"
#include "algm/Node36.h"
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
// @test([4,2,5,1,3])=[1,2,3,4,5]
// @test([28,-98,67,null,-89,62,null,-97,-25,null,64,null,null,-72,-9,null,null,-88,-41,null,-7,null,-78,-53,null,null,2,-85,-77,-69,-42,-1])=[-98,-97,-89,-88,-85,-78,-77,-72,-69,-53,-42,-41,-25,-9,-7,-1,2,28,62,64,67]
class Solution {
public:
    // Node* treeToDoublyList(Node* root) {
    //     if (!root) return nullptr;
    //     stack<Node*> st;
    //     Node* p = root;
    //     Node* head;
    //     Node* r = nullptr;
    //     while (!st.empty() || p) {
    //         if (p) {
    //             st.push(p);
    //             p = p->left;
    //         }
    //         else {
    //             p = st.top();
    //             st.pop();
    //             if (!r) head = p;
    //             Node* temp = p;
    //             p = p->right;
    //             if (r) r->right = temp;
    //             temp->left = r;
    //             r = temp;
    //         }
    //     }
    //     //处理第一个节点和最后一个节点
    //     r->right = head;
    //     head->left = r;
    //     return head;
    // }

    Node* pre, *head;
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        inor(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
    void inor(Node* root) {
        if (!root) return ;
        if (root->left) inor(root->left);
        if (!pre) head = root;
        else pre->right = root;
        root->left = pre;
        pre = root;
        if (root->right) inor(root->right);
    }
};