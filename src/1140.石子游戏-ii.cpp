/*
 * @lc app=leetcode.cn id=1140 lang=cpp
 *
 * [1140] 石子游戏 II
 */

// @lc code=start
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        int pre_sum = 0;
        for (int i = n; i >= 1; i--) {
            pre_sum += piles[i-1];
            for (int j = 1; j <= n; j++) {
                if (2 * j >= n - i + 1) {
                    dp[i][j] = pre_sum;
                } else {
                    for (int k = 1; k <= 2 * j; k++) {
                        dp[i][j] = max(dp[i][j], pre_sum - dp[i + k][max(j, k)]);
                    }
                }
            }
        }
        return dp[1][1];
    }
};
// @lc code=end

