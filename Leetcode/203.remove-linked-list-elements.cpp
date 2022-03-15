// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem203.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    //采用双指针，一次遍历的方式.其实使用一个指针也是可以做到的。
    ListNode* removeElements(ListNode* head, int val) {
        while (head != nullptr && head->val == val) {
            ListNode* temp = head;  // 设置一个临时节点，用于删除内存中的节点
            head = head->next;
            delete temp;
        }
        if (head == nullptr) return nullptr;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast != nullptr) {
            if (fast->val == val) {
                ListNode* temp = fast;
                slow->next = fast->next;
                fast = fast->next;
                delete temp;
            }
            else {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return head;
    }
};
// @lc code=end

