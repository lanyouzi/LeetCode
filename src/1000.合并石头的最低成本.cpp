/*
 * @lc app=leetcode.cn id=1000 lang=cpp
 *
 * [1000] 合并石头的最低成本
 */

// @lc code=start
class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0) {
            return -1;
        }
        vector dp(n+1, vector(n+1, vector<int>(k+1, 0x3f3f3f3f)));
        // dp[i][j][k]表示将i~j的石堆合并为k堆所需的最小成本
        vector<int> pre_sum(n+1, 0);
        for (int i=1; i<=n; i++) {
            pre_sum[i] = pre_sum[i-1] + stones[i-1];
        }
        for (int i=1; i<=n; i++) {
            dp[i][i][1] = 0;
        }
        for (int len=2; len<=n; len++) {        // 枚举区间长度
            for (int i = 1; i+len-1<=n; i++) {  // 枚举左端点
                int j = i+len-1;                // 计算右端点
                for (int m=2; m<=k; m++) {      // 枚举堆数
                    for (int p=i; p<j; p+=(k-1)) {  // 要使得dp[i][p][1]有解，(p-i+1) % (m-1) = 0
                        dp[i][j][m] = min(dp[i][j][m], dp[i][p][1]+dp[p+1][j][m-1]);
                    }
                }
                dp[i][j][1] = dp[i][j][k]+pre_sum[j]-pre_sum[i-1];
            }
        }
        return dp[1][n][1];
    }
};
// @lc code=end

