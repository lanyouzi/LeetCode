/*
 * @lc app=leetcode.cn id=1092 lang=cpp
 *
 * [1092] 最短公共超序列
 */

// @lc code=start

/* 
先求最长公共子序列，然后从后往前逆向构造。
 */
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        string ans;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (str1[i-1]==str2[j-1]) {
                    dp[i][j] = dp[i-1][j-1]+1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int i = n-1, j = m-1;
        while (i>=0 && j>=0) {
            if (str1[i]==str2[j]) {
                ans+=str1[i];
                i--;
                j--;
            } else {
                if (dp[i][j+1]>dp[i+1][j]) {
                    ans+=str1[i];
                    i--;
                } else {
                    ans+=str2[j];
                    j--;            
                }
            }
        }
        while (i>=0) {
            ans+=str1[i--];
        }
        while (j>=0) {
            ans+=str2[j--];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

