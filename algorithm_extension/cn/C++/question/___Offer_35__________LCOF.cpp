// @algorithm @lc id=100300 lang=cpp 
// @title fu-za-lian-biao-de-fu-zhi-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
#include "algm/Node35.h"
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
// @test([[3,null],[3,0],[3,null]])=[[3,null],[3,0],[3,null]]
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        //复制节点
        Node* cur = head;
        while (cur) {
            Node* node = new Node(cur->val);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        
        //复制random指针
        cur = head;
        while (cur) {
            if (cur->random)
            cur->next->random = cur->random->next;
            else cur->next->random = nullptr;
            cur = cur->next->next;
        }
        //取出复制后的链表,并还原原来的链表
        cur = head->next;
        Node* pre = head;
        Node* res = head->next;
        while (cur->next) {
            pre->next = pre->next->next;
            pre = pre->next;
            cur->next = cur->next->next;
            cur = cur->next;
        }
        pre->next = pre->next->next;
        return res;
    }
};