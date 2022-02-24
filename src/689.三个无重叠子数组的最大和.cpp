/*
 * @lc app=leetcode.cn id=689 lang=cpp
 *
 * [689] 三个无重叠子数组的最大和
 */

// @lc code=start
class Solution {
   public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> ans;
        // 滑动窗口，分别从下标为0，k，2k依次遍历
        int sum1 = 0, sum2 = 0, sum3 = 0;
        int maxSum1 = 0, maxSum12 = 0, maxSum123 = 0;
        int maxSum1Idx1 = 0, maxSum12Idx1 = 0, maxSum12Idx2=0;
        for (int i = 2 * k; i < nums.size(); i++) {
            sum1 += nums[i - 2 * k];
            sum2 += nums[i - k];
            sum3 += nums[i];
            if (i >= 3 * k - 1) {
                if (sum1 > maxSum1) {
                    maxSum1 = sum1;
                    maxSum1Idx1 = i - 3 * k + 1;
                }
                if (maxSum1 + sum2 > maxSum12) {
                    maxSum12 = maxSum1 + sum2;
                    maxSum12Idx1 = maxSum1Idx1;
                    maxSum12Idx2 = i-2*k+1;
                }
                if (maxSum12 + sum3 > maxSum123) {
                    maxSum123 = maxSum12 + sum3;
                    ans = {maxSum12Idx1, maxSum12Idx2, i - k + 1};
                }
                sum1 -= nums[i - 3 * k + 1];
                sum2 -= nums[i - 2 * k + 1];
                sum3 -= nums[i - k + 1];
            }
        }
        return ans;
    }
};
// @lc code=end
