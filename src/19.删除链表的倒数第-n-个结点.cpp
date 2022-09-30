/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int num = 0;  // number of nodes in linklist
        ListNode* p = new ListNode();
        p->next = head;
        head = p;
        while (p->next!=nullptr) {
            p = p->next;
            num++;
        }
        p = head;
        int forward = num-n;
        for (int i=0; i<forward; i++) {
            p = p->next;
        }
        ListNode* q = p->next;
        p->next = q->next;
        return head->next;
    }
};
// @lc code=end

