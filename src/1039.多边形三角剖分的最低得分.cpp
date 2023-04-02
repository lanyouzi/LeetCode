/*
 * @lc app=leetcode.cn id=1039 lang=cpp
 *
 * [1039] 多边形三角剖分的最低得分
 */

// @lc code=start
class Solution {
public:

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i=3; i<=n; i++) {  // interval length
            for (int l=0; l+i-1<n; l++) {  // interval start
                int r = l+i-1;
                dp[l][r] = INT_MAX;
                for (int k=l+1; k<r; k++) {
                    dp[l][r] =min(dp[l][r], dp[l][k]+dp[k][r]+values[l]*values[k]*values[r]);
                } 
            }
        }
        return dp[0][n-1];
    }
};
// @lc code=end

