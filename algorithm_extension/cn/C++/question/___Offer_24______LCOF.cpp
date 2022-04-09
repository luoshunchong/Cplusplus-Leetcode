// @algorithm @lc id=100298 lang=cpp 
// @title fan-zhuan-lian-biao-lcof


#include <iostream>
#include <vector>
#include <string>
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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* cur = head;
        ListNode* pre = nullptr;
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