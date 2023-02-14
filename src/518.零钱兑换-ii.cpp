/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector dp(n+1, vector<int>(amount+1, 0));
        for (int i=1; i<=n; i++) {
            dp[i][0] = 1;   // 无论有几个物品，总有总金额为0的物品
        }
        for (int j=1; j<=amount; j++) {
            if (j%coins[0]==0) {
                dp[1][j] = 1;
            }
        }
        for (int i=2; i<=n; i++) {
            for (int j=1; j<=amount; j++) {
                for (int k=j; k>=0; k-=coins[i-1]) {
                    dp[i][j] += dp[i-1][k];
                }
            }
        }
        return dp[n][amount];
    }
};
// @lc code=end

