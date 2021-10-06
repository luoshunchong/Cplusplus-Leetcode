// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem160.h"

using namespace std;
// @before-stub-for-debug-end

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
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB)
            return nullptr;
        int la = 0, lb = 0, temp = 0;
        ListNode *pa = headA, *pb = headB;
        //求A链表的长度
        while (pa)
        {
            pa = pa->next;
            la++;
        }
        //求B链表的长度
        while (pb)
        {
            pb = pb->next;
            pb++;
        }
        //让A先走
        if (pa >= pb)
        {
            temp = pa - pb;
            while (temp)
            {
                headA = headA->next;
                temp--;
            }
        }
        else
        { //让B先走
            temp = pb - pa;
            while (temp)
            {
                headB = headB->next;
                temp--;
            }
        }
        //让两个一起走
        while (headA && headB)
        {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};
// @lc code=end
