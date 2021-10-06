/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        int lengthA = 0, lengthB = 0;
        //求链表A的长度
        ListNode *p1 = headA;
        while (p1 != nullptr)
        {
            lengthA++;
            p1 = p1->next;
        }
        //求链表B的长度
        ListNode *p2 = headB;
        while (p2 != nullptr)
        {
            lengthB++;
            p2 = p2->next;
        }
        //先让长的走一走
        if (lengthB >= lengthA)
        {
            int k = lengthB - lengthA;
            while (k > 0)
            {
                headB = headB->next;
                k--;
            }
        }
        else
        {
            int k = lengthA - lengthB;
            while (k > 0)
            {
                headB = headA->next;
                k--;
            }
        }
        //两者再同时走，直到走到交叉点
        while (headA != nullptr && headB != nullptr)
        {
            if (headA != headB)
            {
                headA = headA->next;
                headB = headB->next;
            }
            else
            {
                return headA;
            }
        }
        return nullptr;
    }
};
// @lc code=end

