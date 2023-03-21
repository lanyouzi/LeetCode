/*** 
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2023-03-13 16:45:40
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-03-13 18:46:05
 * @FilePath: 42.接雨水.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by lanyouzi, All Rights Reserved. 
 */
/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        // double pointers
        int n = height.size(), ans = 0;
        int left = 0, right = n-1;
        int left_max = 0, right_max = 0;
        while (left<right) {
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);
            if (height[left]<height[right]) {   // 等价于left_max < right_max
                /* 
                关于等价性：由于一直是高度较低的指针移动，因此移动前另一方总会满足当前高度等于最大高度
                 */
                ans += (left_max-height[left]);
                left++;
            } else {
                ans += (right_max-height[right]);
                right--;
            }
        }
        return ans;

        // dp
        // int n = height.size(), ans = 0;
        // left[i]表示下标i前（包含）的最大柱高，right[i]表示下标i后（包含）的最大柱高
        // vector<int> left(n, height[0]), right(n, height[n-1]);
        // for (int i=1; i<n; i++) {
        //     left[i] = max(left[i-1], height[i]);
        // }
        // for (int i=n-2; i>=0; i--) {
        //     right[i] = max(right[i+1], height[i]);
        // }
        // for (int i=0; i<n; i++) {
        //     int rest = min(left[i], right[i])-height[i];
        //     if (rest>0)
        //         ans+=rest;
        // }
        // return ans;
    }
};
// @lc code=end

