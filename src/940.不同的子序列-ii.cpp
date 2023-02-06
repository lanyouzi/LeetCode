/*
 * @lc app=leetcode.cn id=940 lang=cpp
 *
 * [940] 不同的子序列 II
 */

// @lc code=start
const int MOD = 1000000000 + 7;
class Solution {
   public:
    const int MOD = 1E9 + 7;
    int distinctSubseqII(string s) {
        int n = s.size(), ans = 0;
        map<char, int> mp;  // last occur index
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (auto it : mp) {
                dp[i] = (dp[i] + dp[it.second]) % MOD;
            }
            mp[s[i]] = i;
        }
        for (auto it : mp) {
            ans = (ans + dp[it.second]) % MOD;
        }
        return ans;
    }
};
// @lc code=end
