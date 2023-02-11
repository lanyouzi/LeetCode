/*** 
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2023-02-09 10:08:28
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-02-10 14:56:56
 * @FilePath: \LeetCode\src\10.正则表达式匹配.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
bool isMatch(string s, string p) {
    int slen = s.size(), plen = p.size();
    vector<vector<bool>> dp(slen+1, vector<bool>(plen+1, false));
    dp[0][0] = true;
    for (int j=1; j<=plen; j++) {
        if (p[j-1]=='*') {
            dp[0][j] = dp[0][j-2];
        }
    }
    for (int i=1; i<=slen; i++) {
        for (int j=1; j<=plen; j++) {
            if (s[i-1]==p[j-1] || p[j-1]=='.') {    // last char match
                dp[i][j] = dp[i-1][j-1];
            } else if (p[j-1]=='*') {
                if (s[i-1]==p[j-2] || p[j-2]=='.') {
                    dp[i][j] = dp[i][j-2] || dp[i-1][j-2] || dp[i-1][j];
                } else {
                    dp[i][j] = dp[i][j-2];
                }
            }
        }
    }
    return dp[slen][plen];  // judge if s with length slen matchs p with length plen
}
};
// @lc code=end

