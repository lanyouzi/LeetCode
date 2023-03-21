/***
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2023-03-13 18:47:25
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-03-13 19:10:34
 * @FilePath: heap_sort.cpp
 * @Description:
 * @
 * @Copyright (c) 2023 by lanyouzi, All Rights Reserved.
 */
#include <bits/stdc++.h>
using namespace std;

void filter_down(vector<int>& nums, int i, int l, bool less) {
    while (i < nums.size()) {
        if (2 * i + 1 >= l) {
            return;
        }
        int left = nums[2 * i + 1];
        int right;
        bool go_left;
        if (less) {
            right = 2 * i + 2 < l ? nums[2 * i + 2] : INT_MIN;
            int max_val = max(left, right);
            go_left = (left > right);
            if (nums[i] >= max_val) {
                return;
            }
        } else {
            right = 2 * i + 2 < l ? nums[2 * i + 2] : INT_MAX;
            int min_val = min(left, right);
            go_left = (left < right);
            if (nums[i] <= min_val) {
                return;
            }
        }
        if (go_left) {
            swap(nums[i], nums[2 * i + 1]);
            i = 2 * i + 1;
        } else {
            swap(nums[i], nums[2 * i + 2]);
            i = 2 * i + 2;
        }
    }
}
void heap_sort(vector<int>& nums, bool less = true) {
    // heap initialization
    int n = nums.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        filter_down(nums, i, n, less);
    }
    //
    for (int i = n - 1; i >= 0; i--) {
        swap(nums[0], nums[i]);
        filter_down(nums, 0, i, less);
    }
}
int main() {
    vector<int> v = {3, 2, 6, 8, 4, 7, 9, 0};
    heap_sort(v);
    for (auto& item : v) {
        cout << item << " ";
    }
    return 0;
}