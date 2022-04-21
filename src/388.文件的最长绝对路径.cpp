/*
 * @lc app=leetcode.cn id=388 lang=cpp
 *
 * [388] 文件的最长绝对路径
 */

// @lc code=start
class Solution {
   public:
    int lengthLongestPath(string s) {
        vector<int> dp(1e4 + 10, 0);
        int res = 0, i = 0;
        int n = s.size();
        dp[0] = 0;
        while (i < n) {
            int layer = 1;      // layer = num(\t)+1
            while (i < n && s[i] == '\t') {
                layer++;
                i++;
            }
            int len = 0;
            bool isfile = false;
            while (i < n && s[i] != '\n') {
                if (!isfile && s[i] == '.')
                    isfile = true;
                len++;
                i++;
            }
            i++;
            dp[layer] = len + dp[layer - 1];
            if (isfile)
                res = max(res, dp[layer] + layer - 1);
        }
        return res;
    }
};
// @lc code=end
