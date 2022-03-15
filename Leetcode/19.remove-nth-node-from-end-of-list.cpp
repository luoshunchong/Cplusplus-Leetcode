/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    //使用虚拟节点,快慢指针
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        ListNode* fast = dummyHead;
        //让fast先走
        while (n > 0) {
            fast = fast->next;
            n--;
        }
        //两个指针一起走
        while (fast->next) {
            fast = fast->next;
            cur = cur->next;
        }
        //删除节点
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        
        return dummyHead->next;
    }
};
// @lc code=end

