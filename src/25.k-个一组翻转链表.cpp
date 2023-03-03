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
        ListNode* p = new ListNode(0, head);
        head = p;
        ListNode* pre = head;
        p = p->next;
        while (p != nullptr || st.size()==k) {
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
                        pre->next = p;
                    }
                }
            }
        }
        return head->next;
    }
};