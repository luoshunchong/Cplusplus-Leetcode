/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    //采用虚拟头结点
    ListNode* swapPairs(ListNode* head) {
        if (!head) return nullptr;
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tem1 = cur->next;
            ListNode* tem2 = cur->next->next;
            //交换两个节点
            cur->next = tem2;
            tem1->next = tem2->next;
            tem2->next = tem1;
            //移动cur的位置
            cur = tem1;
        }
        return dummyHead->next; 
    }
};
// @lc code=end

