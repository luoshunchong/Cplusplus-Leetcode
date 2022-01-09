/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */

// @lc code=start
class MyLinkedList {
public:

    // 定义节点结构体
    struct LinkedNode {
        /* data */
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val), next(nullptr){}
    };
    
    // 默认构造函数,也是初始化链表
    MyLinkedList() {
        // 这里定义的头结点 是一个虚拟头结点，而不是真正的链表头结点
        Initialize = new LinkedNode(0);
        int _size = 0;
    }
    
    int get(int index) {
        if (index > (_size - 1) || index < 0) {
            return -1;
        }
        LinkedNode* temp = Initialize->next;
        while (index--) {  // 如果--index 就会陷入死循环 
            temp = temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        //采用头插法
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = Initialize->next;
        Initialize->next = newNode;
        _size++;
    }
    
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = Initialize;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > _size) {
            return ;
        }
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = Initialize;
        while (cur->next->val != index) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= _size || index < 0) {
            return ;
        }
        LinkedNode* cur = Initialize;
        while (cur->next->val != index) {
            cur = cur->next;
        }
        LinkedNode* temp = cur->next;
        cur->next = temp->next;
        delete temp;
        _size--;
    }

private:
    int _size;
    LinkedNode* Initialize;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

