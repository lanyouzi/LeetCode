/***
 * @Author: lanyouzi mrk_lanyouzi@yeah.net
 * @Date: 2023-03-17 17:40:05
 * @LastEditors: lanyouzi mrk_lanyouzi@yeah.net
 * @LastEditTime: 2023-03-17 17:40:30
 * @FilePath: binary_search.cpp
 * @Description:
 * @
 * @Copyright (c) 2023 by lanyouzi, All Rights Reserved.
 */
#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int>& v, int target, int l, int r) {
    if (l >= r) {
        return -1;
    }
    int mid = (l + r) / 2;
    if (v[mid] == target) {
        return mid;
    } else if (v[mid] < target) {
        return binary_saerch(v, target, mid + 1, r);
    } else {
        return binary_saerch(v, target, l, mid - 1);
    }
}

int upper_idx, lower_idx;
// 不小于目标的第一个元素
void binary_search_lower_bound(vector<int>& nums,
                               int left,
                               int right,
                               int target) {
    if (left > right)
        return;
    int mid = (left + right) / 2;
    if (target <= nums[mid]) {
        lower_idx = mid;
        binary_search_lower_bound(nums, left, mid - 1, target);
    } else {
        binary_search_lower_bound(nums, mid + 1, right, target);
    }
}

// 大于目标的第一个元素
void binary_search_upper_bound(vector<int>& nums,
                               int left,
                               int right,
                               int target) {
    if (left > right)
        return;
    int mid = (left + right) / 2;
    if (target < nums[mid]) {
        binary_search_upper_bound(nums, left, mid - 1, target);
    } else {
        upper_idx = mid + 1;
        binary_search_upper_bound(nums, mid + 1, right, target);
    }
}
int main() {
    vector<int> v = {1, 4, 7, 9, 11, 16};
    cout << binary_saerch(v, 7, 0, 5);
    return 0;
}