/*
 * @lc app=leetcode.cn id=1669 lang=cpp
 *
 * [1669] 合并两个链表
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* ahead = new ListNode(0, list1);
        ListNode *p = ahead, *q = ahead;
        ListNode *bhead = list2, *btail = list2;
        while (btail->next != nullptr) {
            btail = btail->next;
        }
        for (int i = 0; i < a; i++) {
            p = p->next;
        }
        for (int i = 0; i <= b; i++) {
            q = q->next;
        }
        p->next = bhead;
        btail->next = q->next;
        return ahead->next;
    }
};
// @lc code=end
