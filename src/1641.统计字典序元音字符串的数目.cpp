/*
 * @lc app=leetcode.cn id=1641 lang=cpp
 *
 * [1641] 统计字典序元音字符串的数目
 */

// @lc code=start
class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1, vector<int>(5, 0));
        for (int i=0; i<5; i++) {
            dp[1][i] = 1;
        }
        for (int i=2; i<=n; i++) {
            for (int j=0; j<5; j++) {
                for (int k=j; k<5; k++) {
                    dp[i][j]+=dp[i-1][k];
                }
            }
        }
        return accumulate(dp[n].begin(), dp[n].end(), 0);
    }
};
// @lc code=end

