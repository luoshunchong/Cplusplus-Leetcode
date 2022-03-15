/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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
    ListNode *detectCycle(ListNode *head) {//使用快慢指针，Floyd判圈法
        ListNode *fast=head,*slow=head;
        //判断是否存在回路
        //使用do-while循环，第一遍的目的是为了先判断链表是否为空
        //快指针一次前进两个单位，慢指针一次前进一个单位
        //如果快指针可以追上慢指针，说明有回路，在第一次相遇后，将
        //快指针移到表头，并让快慢指针都一次前进一个单位，当他们第二次相遇
        //相遇的地点就是环路的开始节点
        do{
            if(!fast||!fast->next) return nullptr;
            fast=fast->next->next;
            slow=slow->next;
        }while(fast!=slow);
        //如果存在，查找环路节点
        fast=head;
        while(fast!=slow){
            slow=slow->next;
            fast=fast->next;
        }
        return fast;
    }
};
// @lc code=end

