/*** 
 * @Author: lanyouzi lanyouzi@zju.edu.cn
 * @Date: 2023-03-27 22:03:48
 * @LastEditors: lanyouzi lanyouzi@zju.edu.cn
 * @LastEditTime: 2023-03-27 22:03:53
 * @FilePath: 1638.统计只差一个字符的子串数目.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by lanyouzi, All Rights Reserved. 
 */
/*
 * @lc app=leetcode.cn id=1638 lang=cpp
 *
 * [1638] 统计只差一个字符的子串数目
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s, string t) {
        int ans = 0;
        int n = s.size(), m = t.size();
        vector<vector<int>> dpl(n+2, vector<int>(m+2, 0)), dpr(n+2, vector<int>(m+2, 0));
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                dpl[i][j] = s[i-1]==t[j-1]?dpl[i-1][j-1]+1:0;
            }
        }
        for (int i=n; i>=1; i--) {
            for (int j=m; j>=1; j--) {
                dpr[i][j] = s[i-1]==t[j-1]?dpr[i+1][j+1]+1:0;
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (s[i-1]!=t[j-1]) {
                    int left = dpl[i-1][j-1]+1, right = dpr[i+1][j+1]+1;
                    ans+=left*right;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

