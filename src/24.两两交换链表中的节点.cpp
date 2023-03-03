/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *p = new ListNode(0);
        p->next = head;
        head = p;
        while (p->next && p->next->next) {
            ListNode *q = p->next;
            ListNode *r = p->next->next;
            q->next = r->next;
            r->next = q;
            p->next = r;
            p = q;
        }
        return head->next;
    }
};
// @lc code=end

