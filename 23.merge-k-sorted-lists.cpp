// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem23.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    /*
    将数组中链表的所有节点值全部存储到listnum中去，再排序，
    再采用头插法构建链表。
    时间复杂度：NlogN,其中N为节点的总数目。
    空间复杂度:N
    */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> listnum;
        for (int i = 0; i < lists.size(); ++i) {
            ListNode* head = lists[i];
            while (head) {
                listnum.push_back(head->val);
                head = head->next;
            }
        }
        sort(listnum.begin(), listnum.end());
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;
        for (int i = 0; i < listnum.size(); ++i) {
            ListNode* temp = new ListNode(listnum[i]);
            //头插法构建链表
            cur->next = temp;
            cur = temp;
        }
        return dummyHead->next;
    }
};
// @lc code=end

