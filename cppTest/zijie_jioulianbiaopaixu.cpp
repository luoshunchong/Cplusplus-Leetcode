#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {};
};

ListNode* buildListNode(vector<int>& nums) {
    ListNode* dummyhead = new ListNode(10001);
    ListNode* p = dummyhead;
    for (int i = 0; i < nums.size(); ++i) {
        ListNode* node = new ListNode(nums[i]);
        p->next = node;
        p = p->next;
    }
    return dummyhead->next;
}

//反转链表
ListNode* reverse(ListNode* a) {
    ListNode* pre = nullptr;
    ListNode* cur = a;
    ListNode* next = nullptr;
    while (cur) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

ListNode* megreListNode(ListNode* a, ListNode* b) {
    if (!a) return b;
    if (!b) return a;
    ListNode* dummyhead = new ListNode(1001);
    ListNode* p = dummyhead;
    while (a && b) {
        if (a->val < b->val) {
            p->next = a;
            a = a->next;
        }
        else {
            p->next = b;
            b = b->next;
        }
        p = p->next;
    }
    if (a) p->next = a;
    if (b) p->next = b;
    return dummyhead->next;
}

ListNode* check(ListNode* head) {
    if (!head || !head->next) return head;
    //奇偶链表拆开
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* p1 = odd;
    ListNode* p2 = even;
    ListNode* p = even->next;
    while (p) {
        p1->next = p;
        p2->next = p->next;
        p1 = p1->next;
        p2 = p2->next;
        if (p->next) p = p->next->next;
        else break;
    }
    p1->next = nullptr;
    p2->next = nullptr;
    //反转偶数链表
    ListNode* even1 = reverse(even);
    //合并链表
    ListNode* res = megreListNode(odd, even1);
    return res;
}

int main() {
    vector<int> nums = {1,8,3,6,5,4,7,2};
    ListNode* head = buildListNode(nums);
    ListNode* res = check(head);
    while (res) {
        cout << res->val << "->" ;
        res = res->next;
    }
    cout << "nullptr" << endl;
    return 0;
}