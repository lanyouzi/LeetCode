/*
 * @Author: mrk-lyz mrk_lanyouzi@yeah.net
 * @Date: 2022-07-16 10:19:09
 * @LastEditTime: 2022-07-16 10:21:05
 * @FilePath: /LeetCode/src/剑指 Offer II 041. 滑动窗口的平均值.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by mrk-lyz mrk_lanyouzi@yeah.net, All Rights Reserved. 
 */
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), k = max(m, n);
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i=2; i<=2*k; i++) {
            for (int j=1; j<i; j++) {
                if (j<=m && (i-j)<=n) {
                    dp[j][i-j] = max(dp[j-1][i-j], dp[j][i-j-1]) + grid[j-1][i-j-1];
                }
                    
            }
        }
        return dp[m][n];
    }
};