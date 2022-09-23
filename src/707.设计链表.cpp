/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
struct Node {
    int val;
    Node* next;
    Node (int _val): val(_val) {
        next = nullptr;
    }
};
class MyLinkedList {
public:
    Node *head;
    int cnt;
    MyLinkedList() {
        head = new Node(0);
        cnt = 0;
    }
    
    int get(int index) {
        if (index>cnt) {
            return -1;
        }
        Node *p = head;
        for (int i=0; i<=index; i++) {
            p = p->next;
        }
        return p->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(cnt, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index > cnt) {
            return;
        } else if (index < 0) {
            index = 0;
        }
        Node *p = head;
        for (int i=0; i<index; i++) {
            p = p->next;
        }
        Node *q = p->next;
        Node *t = new Node(val);
        p->next = t;
        t->next = q;
        cnt++;
    }
    
    void deleteAtIndex(int index) {
        if (index<0 || index>=cnt) {
            return;
        }
        Node *p = head;
        for (int i=0; i<index; i++) {
            p = p->next;
        }
        Node *q = p->next;
        p->next = q->next;
        delete q;
        cnt--;
    }
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

