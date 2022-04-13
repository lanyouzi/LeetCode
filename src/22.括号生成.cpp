/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

/*
动态规划：在已知前i-1对括号的情况下，求解i对答案
考虑最后结果中最左侧字符必为左括号（下称A），与之匹配有一个右括号（B），则剩下i-1对的情况，可以拆分为p+q，其中p在B左边边，q在B右边，即'('+p+')'+q
 */
// @lc code=start
class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        if (n == 0)
            return {};
        if (n == 1)
            return {"()"};
        vector<vector<string>> dp(n + 1);
        dp[0] = {""};
        dp[1] = {"()"};
        for (int i = 2; i <= n; i++) {  // traverse dp
            for (int j = 0; j < i; j++) {
                for (auto& p : dp[j])
                    for (auto& q : dp[i - j - 1]) {
                        string str = "(" + p + ")" + q;
                        dp[i].push_back(str);
                    }
            }
        }
        return dp[n];
    }
};
// @lc code=end
