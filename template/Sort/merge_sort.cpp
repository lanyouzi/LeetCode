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
vector<int> merge_array(vector<int>& v, int al, int ar, int bl, int br) {
    size_t i = 0, j = 0, k = 0;
    size_t alen = ar - al, blen = br - bl;
    vector<int> c(alen + blen, 0);
    while (i < alen && j < alen) {
        if (v[bl + j] < v[al + i]) {  // <!> 先判断 b[j] < a[i]，保证稳定性
            c[k] = v[bl + j];
            ++j;
        } else {
            c[k] = v[al + i];
            ++i;
        }
        ++k;
    }
    // 此时一个数组已空，另一个数组非空，将非空的数组并入 c 中
    for (; i < alen; ++i, ++k)
        c[k] = v[al + i];
    for (; j < alen; ++j, ++k)
        c[k] = v[bl + j];
    return c;
}

void merge_sort_array(vector<int>& v, int l, int r) {
    if (r - l <= 1)
        return;
    // 分解
    int mid = l + ((r - l) >> 1);
    merge_sort_array(v, l, mid);
    merge_sort_array(v, mid, r);
    // 合并
    auto tmp = merge_array(v, l, mid, mid, r);  // pointer-style merge
    for (int i = l; i < r; ++i)
        v[i] = tmp[i - l];
}

int main() {
    // vector<int> v = {2, 5, 7, 1, 8};
    // quick_sort(v, 0, v.size()-1);
    // for (auto &item:v) {
    //     cout << item << " ";
    // }
}