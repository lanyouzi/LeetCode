/*** 
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2023-02-15 17:03:29
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-02-15 20:29:07
 * @FilePath: \LeetCode\templates\sort.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#include<bits/stdc++.h>
using namespace std;

void quick_sort(vector<int>& nums, int l, int r) {
    if (l >= r) {
        return;
    }
    cout << l << " " << r << endl;
    int i = l, j = r, cur = i;
    while (i < j) {
        if (nums[i] > nums[j]) {
            swap(nums[i], nums[j]);
            cur = (cur == i) ? j : i;
        }
        if (cur == i) {
            j--;
        } else {
            i++;
        }
    }
    quick_sort(nums, l, i - 1);
    quick_sort(nums, i + 1, r);
}
