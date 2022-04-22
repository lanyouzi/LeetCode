/*
 * @lc app=leetcode.cn id=396 lang=cpp
 *
 * [396] 旋转函数
 */

// @lc code=start

// F(i+1) = F(i) + sum - n * arr[n-1-i]
class Solution {
   public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            dp[0] += i * nums[i];
        }
        int ans = dp[0];
        for (int i = 0; i < n - 1; i++) {
            dp[i + 1] = dp[i] + sum - n * nums[n - 1 - i];
            if (dp[i + 1] > ans) {
                ans = dp[i + 1];
            }
        }
        return ans;
    }
};
// @lc code=end
