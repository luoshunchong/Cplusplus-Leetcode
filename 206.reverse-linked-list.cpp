/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
        //栈
        if (head == NULL)
            return head;
        stack<ListNode *> temp;
        //入栈
        while (head != NULL)
        {
            temp.push(head);
            head = head->next;
        }
        //出栈
        //创建一个链表来保存反转的链表
        ListNode *res = temp.top();
        ListNode *p = res;
        temp.pop();
        while (!temp.empty())
        {
            res->next = temp.top();
            temp.pop();
            res = res->next;
        }
        res->next = NULL;
        return p;
    }
};
// @lc code=end

