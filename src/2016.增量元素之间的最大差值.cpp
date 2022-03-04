/*
 * @lc app=leetcode.cn id=2016 lang=cpp
 *
 * [2016] 增量元素之间的最大差值
 */

// @lc code=start
class Solution {
   public:
    int maximumDifference(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < dp[i - 1]) {
                dp[i] = nums[i];
            } else {
                dp[i] = dp[i - 1];
            }
        }
        int ans = -1;
        for (int i = 1; i < dp.size(); i++) {
            if (nums[i] > dp[i - 1] && nums[i] - dp[i - 1] > ans) {
                ans = nums[i] - dp[i - 1];
            }
        }
        return ans;
    }
};
// @lc code=end
