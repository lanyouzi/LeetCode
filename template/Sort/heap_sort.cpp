/***
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2023-03-19 10:37:27
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-03-30 22:05:55
 * @FilePath: heap_sort.cpp
 * @Description:
 * @
 * @Copyright (c) 2023 by lanyouzi, All Rights Reserved.
 */
#include <bits/stdc++.h>
using namespace std;

// advanced insertion sort
void shell_sort(vector<int>& nums, bool less = true) {
    // heap initialization
    int n = nums.size();
    for (int step = n/2; step > 0; step /= 2) {
        for (int i = step; i<n; i++) {
            int j = i;
            int temp = nums[j];
            while (j-step>=0 && nums[j-step]>temp) {
                nums[j]=nums[j-step];
                j-=step;
            }
            nums[j] = temp;
        }
    }
}
int main() {
    vector<int> v = {3, 2, 6, 8, 4, 7, 9, 0};
    shell_sort(v);
    for (auto& item : v) {
        cout << item << " ";
    }
    return 0;
}