#include <bits/stdc++.h>

using namespace std;

// linklist type
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* merge_linklist(ListNode* h1, ListNode* h2) {
    ListNode* head = new ListNode(0);
    ListNode *p = h1, *q = h2, *guard = head;
    while (p != nullptr && q != nullptr) {
        if (q->val < p->val) {
            guard->next = q;
            q = q->next;
        } else {
            guard->next = p;
            p = p->next;
        }
        guard = guard->next;
    }
    for (; p != nullptr; p = p->next, guard = guard->next) {
        guard->next = p;
    }
    for (; q != nullptr; q = q->next, guard = guard->next) {
        guard->next = q;
    }
    return head->next;
}
ListNode* merge_sort_linklist(ListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }
    if (head->next == nullptr) {
        return head;
    }
    ListNode *fast = head, *slow = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode* head2 = slow->next;
    slow->next = nullptr;
    ListNode* left = merge_sort_linklist(head);
    ListNode* right = merge_sort_linklist(head2);
    ListNode* tmp = merge_linklist(left, right);
    return tmp;
}

// array type
// [al, ar) v.s. [bl, br)
void merge_array(vector<int>& v, int start, int mid, int end) {
    int k = 0, left = start, right = mid;
    // vector<int> c(end-start, 0);
    vector<int> tmp(end-start, 0);
    while (left < mid && right < end) {
        tmp[k++] = v[left] < v[right] ? v[left++] : v[right++];
    }
    while (left < mid)
        tmp[k++] = v[left++];
    while (right < end)
        tmp[k++] = v[right++];
    for (int l = start; l < end; l++)
        v[l] = tmp[l-start];

}

void merge_sort_array(vector<int>& v, int left, int right) {
    if (right - left <= 1)
        return;
    int mid = left + ((right - left) >> 1);
    merge_sort_array(v, left, mid);
    merge_sort_array(v, mid, right);
    merge_array(v, left, mid, right);
}

int main() {
    vector<int> v = {2, 5, 7, 1, 8};
    merge_sort_array(v, 0, 5);
    // quick_sort(v, 0, v.size()-1);
    for (auto& item : v) {
        cout << item << " ";
    }
}