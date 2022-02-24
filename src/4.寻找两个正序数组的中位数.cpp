/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include <bits/stdc++.h>

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, m = nums1.size(), n = nums2.size();
        vector<int> tmp;
        while (i < m || j < n) {
            if (i >= m) {
                tmp.emplace_back(nums2[j]);
                j++;
            } else if (j >= n) {
                tmp.emplace_back(nums1[i]);
                i++;
            } else if (nums1[i] < nums2[j]) {
                tmp.emplace_back(nums1[i]);
                i++;
            } else {
                tmp.emplace_back(nums2[j]);
                j++;
            }
        }
        if (tmp.size() % 2 == 1) {
            return tmp[tmp.size() / 2];
        } else {
            return (tmp[tmp.size() / 2 - 1] * 1.0 + tmp[tmp.size() / 2]) / 2;
        }
    }
};
// @lc code=end
