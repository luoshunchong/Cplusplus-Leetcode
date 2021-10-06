/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        while (head)
        {
            ListNode *p = dummy;
            while (p->next && p->next->val < head->val)
                p = p->next;
            ListNode *q = head;
            head = head->next;
            q->next = p->next;
            p->next = q;
        }
        return dummy->next;
    }
};
// @lc code=end

