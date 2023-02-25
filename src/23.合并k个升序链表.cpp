/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    struct Flag {
        int idx;
        ListNode *p;
        Flag(int _idx, ListNode *_p) {
            idx = _idx;
            p = _p;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = new ListNode(0);
        ListNode *guard = head;
        Flag *tmp;
        int n = lists.size();
        auto cmp = [&](const Flag *a, const Flag *b) {return (a->p->val) > (b->p->val);};
        priority_queue<Flag*, vector<Flag*>, decltype(cmp)> q(cmp);
        for (int i=0; i<n; i++) {
            if (lists[i]!=nullptr) {
                tmp = new Flag(i, lists[i]);
                q.push(tmp);
            }
        }

        while (!q.empty()) {
            Flag *cur = q.top();
            q.pop();
            guard->next = cur->p;
            guard = guard->next;
            int idx = cur->idx;
            lists[idx] = lists[idx]->next;
            if (lists[idx]!=nullptr) {
                tmp = new Flag(idx, lists[idx]);
                q.push(tmp);
            }
        }
        return head->next;
        
    }
};
// @lc code=end

