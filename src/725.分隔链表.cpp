/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        ListNode* p = head;
        int num = 0;
        while (p != nullptr) {
            num++;
            p = p->next;
        }
        int m = num / k, n = num % k;
        p = head;
        ListNode* q = p;
        vector<int> v;
        for (auto i = 0; i < k; i++) {
            ans.emplace_back(p);
            int cm = m;
            if (n > 0) {
                cm++;
                n--;
            }
            v.emplace_back(cm);
            q = p;
            if (p != nullptr) {
                for (auto j = 0; j < cm; j++) {
                    p = p->next;
                }
            }
        }
        for (auto i = 0; i < k; i++) {
            p = ans[i];
            for (auto j = 0; j < v[i] - 1; j++) {
                p = p->next;
            }
            if (p != nullptr)
                p->next = nullptr;
        }
        return ans;
    }
};
// @lc code=end
