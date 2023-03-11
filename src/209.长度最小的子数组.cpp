/*** 
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2023-03-10 09:58:11
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-03-10 10:02:48
 * @FilePath: 209.长度最小的子数组.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by lanyouzi, All Rights Reserved. 
 */
/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0, sum = 0;
        int ans = INT_MAX;
        while (right<n) {
            sum+=nums[right++];
            while (left<n && sum>=target) {     // 直接在收缩左端点的时候修改结果
                ans = min(ans, right-left);
                sum-=nums[left++];
            }
        }
        return ans==INT_MAX?0:ans;
    }
};
// @lc code=end

