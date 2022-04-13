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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }
        stack<ListNode*> st;
        ListNode* p = head;
        ListNode* pre = head;
        ListNode* ans = head;
        for (int i = 0; i < k - 1; i++) {
            ans = ans->next;
        }
        while (p != nullptr || st.size() == k) {
            if (st.size() < k) {
                st.push(p);
                p = p->next;
            } else if (st.size() == k) {
                pre->next = st.top();
                while (!st.empty()) {
                    ListNode* q = st.top();
                    st.pop();
                    if (!st.empty()) {
                        ListNode* t = st.top();
                        q->next = t;
                    } else {
                        pre = q;
                        pre->next =
                            p;  // 这个操作是必须的，可以让未满k个的最后一组也可以加入链表，不然会出现倒数第二组无限循环的情况
                    }
                }
            }
        }
        return ans;
    }
};