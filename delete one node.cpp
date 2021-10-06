#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution
{
public:
    ListNode *deleteNode(ListNode *head, int val)
    {
        if (!head)
            return head;
        ListNode *p = head;
        if (p->val == val)
            head = head->next;
        while (p->next)
        {
            if (p->next->val == val)
            {
                p->next = p->next->next;
            }
            if(p->next)
            p = p->next;
        }
        return head;
    }
};

int main(){
    Solution s;
    ListNode l1(4);
    ListNode l2(5);
    ListNode l3(1);
    ListNode l4(9);
    l1.next=&l2;
    l2.next=&l3;
    l3.next=&l4;


    int val=9;

    ListNode* t=s.deleteNode(&l1,val);
    while(t){
        cout<<t->val<<endl;
        t=t->next;
    }
    system("pause");

    return 0;
}