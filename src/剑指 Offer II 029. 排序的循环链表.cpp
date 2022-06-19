/*
 * @Author: mrk-lyz mrk_lanyouzi@yeah.net
 * @Date: 2022-06-18 12:34:34
 * @LastEditTime: 2022-06-18 13:17:10
 * @FilePath: /LeetCode/src/剑指 Offer II 029. 排序的循环链表.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by mrk-lyz mrk_lanyouzi@yeah.net, All Rights Reserved. 
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
   public:
    Node* insert(Node* head, int insertVal) {
        if (head == nullptr) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        int origin = head->val;
        Node*minp = head, *maxp = head;
        Node *p = head->next;
        while (p!=head) {
            if (p->val<minp->val) {     // the first lowest
                minp = p;
            }
            if (p->val>=maxp->val) {    // the last greatest
                maxp = p;
            }
            p = p->next;
        }
        // cout << minp->val << maxp->val << endl;
        if (insertVal<minp->val || insertVal>maxp->val) {
            maxp->next = new Node(insertVal);
            maxp->next->next = minp;
        } else {
            p = minp;
            while (p->next->val < insertVal) {
                p = p->next;
            }
            Node *tmp = p->next;
            p->next = new Node(insertVal);
            p->next->next = tmp;
        }
        return head;
    }
};