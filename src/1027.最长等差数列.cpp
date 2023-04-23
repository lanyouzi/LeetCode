/*
 * @lc app=leetcode.cn id=1027 lang=cpp
 *
 * [1027] 最长等差数列
 */

// @lc code=start
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        // dp[i][j]表示以第i个元素结尾，公差为j的最长序列长度间隔数量
        int n = nums.size();
        int ans = 0;
        vector<vector<int>> dp(n+1, vector<int>(1001, 0));
        for (int i=2; i<=n; i++) {
            for (int j=i-1; j>=1; j--) {
                int differ = nums[i-1] - nums[j-1];
                dp[i][differ+500] = max(dp[i][differ+500], dp[j][differ+500] + 1);
                ans = max(dp[i][differ+500], ans);
            }
        }
        return ans+1;
    }
};
// @lc code=end

