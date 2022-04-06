// @algorithm @lc id=100282 lang=cpp 
// @title cong-wei-dao-tou-da-yin-lian-biao-lcof


#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "algm/algm.h"
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// @test([1,3,2])=[2,3,1]
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        // //利用栈来存储，并输出。空间复杂度O(n)
        // if (!head) return {};
        // stack<int> st;
        // ListNode* p = head;
        // while (p) {
        //     st.push(p->val);
        //     p = p->next;
        // }
        // vector<int> res;
        // while (!st.empty()) {
        //     res.push_back(st.top());
        //     st.pop();
        // }
        // return res;

        //将链表翻转，再遍历一遍输出就可以了空间复杂度O(1)
        ListNode* p = reverseList(head);
        vector<int> res;
        while (p) {
            res.push_back(p->val);
            p = p->next; 
        }
        return res;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* next = nullptr;
        while (cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};