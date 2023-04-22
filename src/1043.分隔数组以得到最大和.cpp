/*
 * @lc app=leetcode.cn id=1043 lang=cpp
 *
 * [1043] 分隔数组以得到最大和
 */

// @lc code=start
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int ans = 0, n = arr.size();
        vector<int> dp(n+1, 0);
        for (int i=1; i<=n; i++) {
            int max_val = arr[i-1];
            for (int j=i; j>i-k && j>0; j--) {
                max_val = max(max_val, arr[j-1]);
                dp[i] = max(dp[i], dp[j-1]+(i-j+1)*max_val);
            }
        }
        return dp[n];
    }
};
// @lc code=end

