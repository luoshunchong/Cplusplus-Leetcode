/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    // ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    //     ListNode *p=new ListNode();
    //     if(p){
    //         cout<<1<<endl;
    //     }
    //     ListNode *res = p;
    //     while (l1 && l2)
    //     {
    //         if (l1->val <= l2->val)
    //         {
    //             p->next = l1;
    //             l1 = l1->next;
    //             p = p->next;
    //         }
    //         else
    //         {
    //             p->next = l2;
    //             l2 = l2->next;
    //             p = p->next;
    //         }
    //     }
    //     while (l1)
    //     {
    //         p->next = l1;
    //         l1 = l1->next;
    //         p = p->next;
    //     }
    //     while (l2)
    //     {
    //         p->next = l2;
    //         l2 = l2->next;
    //         p = p->next;
    //     }
    //     p->next;
    //     return res->next;
    // }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode();
        ListNode* p = dummyNode;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                p->next = l1;
                l1 = l1->next;
            }
            else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1) {
            p->next = l1;
        }
        if (l2) {
            p->next = l2;
        }
        return dummyNode->next;
    }
};
// @lc code=end

